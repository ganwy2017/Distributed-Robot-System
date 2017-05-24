package org.ros.android.android_tutorial_pubsub;

import org.ros.node.AbstractNodeMain;
import org.ros.node.topic.Publisher;
import org.ros.namespace.GraphName;
import org.ros.node.ConnectedNode;

public class GyroscopeNode extends AbstractNodeMain {

    private String topicName;
    private Publisher publisher = null;

    public GyroscopeNode(String topic) {
        this.topicName = topic;
    }

    @Override
    public GraphName getDefaultNodeName() {
        return GraphName.of("gyroscope_node");
    }

    @Override
    public void onStart(final ConnectedNode connectedNode) {
        // Initialise publisher
        publisher = connectedNode.newPublisher(this.topicName, "std_msgs/String");
    }

    public void publishSensorValues(float[] gyroData) {
        if (publisher != null) {
            // Create a string message
            std_msgs.String message = (std_msgs.String)publisher.newMessage();
            // Write gyroscope data to message
            message.setData(String.format("(%f, %f, %f)", gyroData[0], gyroData[1], gyroData[2]));
            // Publish message
            publisher.publish(message);
        }
    }
}
