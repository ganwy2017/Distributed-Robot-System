package org.ros.android.android_tutorial_pubsub;
import android.os.Bundle;
import org.ros.android.RosActivity;
import org.ros.node.NodeConfiguration;
import org.ros.node.NodeMainExecutor;
import org.ros.address.InetAddressFactory;
import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;

public class MainActivity extends RosActivity implements SensorEventListener {

    public MainActivity() {
        super("Gyroscope Node", "Gyroscope Node");
    }

    private GyroscopeNode gyroscopeNode = null;
    private String topicName = "buggy0/gyroscope0";
    private float[] gyroData = new float[3];
    private SensorManager sensorManager;
    private float tLast = 0;
    private float dt = 0;
    private float t = 0;

    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        // Initialise gyroscope angles
        gyroData[0] = 0.0f;
        gyroData[1] = 0.0f;
        gyroData[2] = 0.0f;
    }

    protected void onResume() {
        super.onResume();
        sensorManager = (SensorManager) this.getSystemService(SENSOR_SERVICE);
        initListeners();
    }

    private void initListeners() {
        sensorManager.registerListener(this,
                sensorManager.getDefaultSensor(Sensor.TYPE_GYROSCOPE),
                sensorManager.SENSOR_DELAY_FASTEST);
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        tLast = t;
        t = event.timestamp;
        if (tLast != 0) {
            // dt = seconds passed since last sensor event
            dt = (t - tLast) / 1e9f;
            if (event.sensor.getType() == Sensor.TYPE_GYROSCOPE) {
                // Integrate event values to get gyro angles 
                gyroData[0] += event.values[0] * dt;
                gyroData[1] += event.values[1] * dt;
                gyroData[2] += event.values[2] * dt;
            }
        }
        // publish gyroscope data
        publishValues();
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {
        // Required but not used
    }

    @Override
    protected void init(NodeMainExecutor nodeMainExecutor) {
        // At this point, the user has already been prompted to either enter the URI
        // of a master to use or to start a master locally.
        // The user can easily use the selected ROS Hostname in the master chooser
        // activity.

        // NodeConfiguration nodeConfiguration = NodeConfiguration.newPublic(getRosHostname());
        // nodeConfiguration.setMasterUri(getMasterUri());

        String host = InetAddressFactory.newNonLoopback().getHostName();
        NodeConfiguration nodeConfiguration = NodeConfiguration.newPublic(host, getMasterUri());

        gyroscopeNode = new GyroscopeNode(topicName);
        nodeMainExecutor.execute(gyroscopeNode, nodeConfiguration);
        // The RosTextView is also a NodeMain that must be executed in order to
        // start displaying incoming messages.
        // nodeMainExecutor.execute(rosTextView, nodeConfiguration);
    }

    private void publishValues() {
        if (gyroscopeNode != null) {
            // If a gyroscope node has been created, publish data
            gyroscopeNode.publishSensorValues(gyroData);
        }
    }
}