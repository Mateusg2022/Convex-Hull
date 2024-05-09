import matplotlib.pyplot as plt

def read_points(filename):
    with open(filename, 'r') as f:
        points = [tuple(map(float, line.strip().split())) for line in f]
    return points

points = read_points('input.txt')

convex_hull_points = read_points('output.txt')
plt.plot(*zip(*points), 'ro')
for i in range(len(convex_hull_points)):
    if i < len(convex_hull_points) - 1:
        plt.plot([convex_hull_points[i][0], convex_hull_points[i+1][0]],
                 [convex_hull_points[i][1], convex_hull_points[i+1][1]], 'b-')
    else:
        plt.plot([convex_hull_points[i][0], convex_hull_points[0][0]],
                 [convex_hull_points[i][1], convex_hull_points[0][1]], 'b-')

plt.title('Convex Hull')
plt.xlabel('X')
plt.ylabel('Y')
plt.show()
