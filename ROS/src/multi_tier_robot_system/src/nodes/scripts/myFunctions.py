

def point_in_poly(pos, poly):                  # Returns True if the point of interest is inside the polygon
    x_ints = []
    n = len(poly)
    inside = False
    p1x, p1y = poly[0]
    for i in range(n+1):
        p2x, p2y = poly[i % n]
        if pos[1] >= min(p1y, p2y):
            if pos[1] < max(p1y, p2y):
                if pos[0] < max(p1x, p2x):
                    if p1y != p2y:
                        x_ints = (pos[1]-p1y)*(p2x-p1x)/(p2y-p1y)+p1x
                    if p1x == p2x or pos[0] <= x_ints:
                        inside = not inside
        p1x, p1y = p2x, p2y
    return inside


def microseconds2cm(microseconds):
    # Speed = 29 microseconds pre centimeter
    # Divide by 2 to account for return journey
    return microseconds / 29.0 / 2.0
