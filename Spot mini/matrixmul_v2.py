import numpy as np
a0=90
a1=0#alpha
a2=0

l1=2.4
l2=9    #link length
l3=13.4
l4=0 # changed to 0
#l1=1
#l2=1
#l3=1
#l4=0
#t0=t0
#t1=90-t1 # formula
#t2=t2

t0=180 ##testedfor 29,8,12
t1=-53 #variable
t2=106

r0=l4
r1=l2   #linklength
r2=l3

d0=l1
d1=0   #d
d2=0

t0=(t0/180)*np.pi
t1=(t1/180)*np.pi
t2=(t2/180)*np.pi
a0=(a0/180)*np.pi
a1=(a1/180)*np.pi
a2=(a2/180)*np.pi
#to is thita and a0 is alpha r and d are variable
m0=[[np.cos(t0) , np.sin(t0)*np.cos(a0)*(-1) , np.sin(t0)*np.sin(a0) , r0*np.cos(t0)] , [np.sin(t0), np.cos(t0)*np.cos(a0), np.cos(t0)*np.sin(a0)*(-1),r0*np.sin(t0)],[0,np.sin(a0),np.cos(a0) , d0],[0,0,0,1]]
m1=[[np.cos(t1) , np.sin(t1)*np.cos(a1)*(-1) , np.sin(t1)*np.sin(a1) , r1*np.cos(t1)] , [np.sin(t1), np.cos(t1)*np.cos(a1), np.cos(t1)*np.sin(a1)*(-1),r1*np.sin(t1)],[0,np.sin(a1),np.cos(a1) , d1],[0,0,0,1]]
m2=[[np.cos(t2) , np.sin(t2)*np.cos(a2)*(-1) , np.sin(t2)*np.sin(a2) , r2*np.cos(t2)] , [np.sin(t2), np.cos(t2)*np.cos(a2), np.cos(t2)*np.sin(a2)*(-1),r2*np.sin(t2)],[0,np.sin(a2),np.cos(a2) , d2],[0,0,0,1]]
#print(m0)
#print("                                                 ")
#print(m1)
#print("                                                 ")
#print(m2)
#print("                                                 ")
m3=np.dot(m0,m1)
#print(m3)
m3 = np.dot(m3,m2)
print((m3))
print(round(12.31267898764,2))

