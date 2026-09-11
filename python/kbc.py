s1={1,2,3,4,5,6}
s2={4,3,2,9,0}
print(s1.union(s2))
print(s1,s2)
# s3= s1.intersection(s2)
# print(s3)
s1.intersection_update(s2)
print(s1)
s2.intersection_update(s1)
print(s2)
print(s1,s2)