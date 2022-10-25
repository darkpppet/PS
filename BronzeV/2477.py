class Area:
    def __init__(self, pathes, lengthes, duplicated_pathes):
        self.long_side = set([1, 2, 3, 4]) - duplicated_pathes
        self.short_side = duplicated_pathes
        self.set_before_and_after_path()
        self.pathes = [x for x in pathes]
        self.lengthes = [x for x in lengthes]

    def set_before_and_after_path(self):
        if (self.short_side == set([1, 3])):
            self.before_path = 1
            self.after_path = 3
        elif (self.short_side == set([2, 4])):
            self.before_path = 2
            self.after_path = 4
        elif (self.short_side == set([3, 2])):
            self.before_path = 3
            self.after_path = 2
        else:
            self.before_path = 4
            self.after_path = 1

    def clac_area(self):
        big_area = 1
        small_area = 1
        for i in range(0, 6):
            if (self.pathes[i] in self.long_side):
                big_area *= self.lengthes[i]

            if (self.is_short_side(i)):
                small_area = self.lengthes[i] * self.lengthes[(i+1) % 6]

        return big_area - small_area

    def is_short_side(self, i):
        if (pathes[i] == self.before_path and pathes[(i+1) % 6] == self.after_path):
            return True
        else:
            return False

k = int(input())

pathes = []
lengthes = []
for i in range(0, 6):
    path, length = [int(x) for x in input().split()]
    pathes.append(path)
    lengthes.append(length)

duplicated_pathes = set(filter(lambda x: pathes.count(x) == 2, pathes))

area = Area(pathes, lengthes, duplicated_pathes)

print(area.clac_area() * k)
