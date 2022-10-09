#to calculate the average of a student height
student_heights = input("input a list of student heights: ").split()
for n in range (0, len(student_heights)):
    student_heights[n] = int(student_heights[n])
print(student_heights)  




total_height = 0
for height in student_heights:
    total_height = total_height = height
print(total_height)


num_of_student = len(student_heights)
average_height  = round(total_height / num_of_student)
print(average_height)

