# class AcornEntry:
#     def __init__(self):
#         self.mymark = 100

# acorn = AcornEntry()
# print(acorn.mymark)
# acorn.yourmark = 90
# print(acorn.yourmark)

#most attributes you can add whatever you want whenever you want


#usual way to use init
class AcornEntry:
    def __init__(self, course, mark):
        self.course = course
        self.mark = mark

    def __repr__(self):
        return f"The mark in {self.course} is {self.mark}"
    
    def __lt__(self, other):
        # if self.course < other.course:
        #     return True
        # elif self.course == other.course:
        #     return self.mark < other.mark
        # else:
        #     return False  #sorted by course then mark
        return(self.mark, self.course) < (other.mark, other.course) #sorted by mark first then course name

#function and operato overloading 
#define how addition, conv to string, comparison, work for the custom class 
acorn_artsie = AcornEntry("CSC108", 100)
acorn_engsci = AcornEntry("CIV102", 8)

entries = [AcornEntry("ESC180", 90),
           AcornEntry("ESC190", 87),
           AcornEntry("MAT185", 85),
           AcornEntry("ESC190", 89)]#89 will be after 87 as they are same course

print(entries[0].__lt__(entries[1])) #
entries.sort()
print(entries)

# print(acorn_artsie)
# print(acorn_artsie > acorn_engsci)