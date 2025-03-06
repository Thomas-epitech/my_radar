from random import uniform as rd

def generate_plane_line():
    return f"A {rd(0, 1920)} {rd(0, 1080)} {rd(0, 1920)} {rd(0, 1080)} {rd(30, 90)} {rd(0, 30)}"
def generate_tower_line():
    return f"T {rd(0, 1920)} {rd(0, 1080)} {rd(10, 70)}"

nb_planes = 100000
nb_towers = 35
for i in range(nb_planes):
    print(generate_plane_line())
for i in range(nb_towers):
    print(generate_tower_line())
