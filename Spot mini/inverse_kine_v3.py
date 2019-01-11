import numpy as np
#import time
#import serial
#ser= serial.Serial('/dev/ttyUSB0',baudrate = 9600)
"""x=-21											# checkthe purposely imposed condition on y 
y=-0
z=9"""
x=-19
y=0
z=9.4
#a1=2.4
#a2=9
#a3=13.4
a1=2.4
a2=9
a3=13.4
t2phi=0
t1=0

if(x!= 0):
	t1=np.arctan2(y,x)
elif(y>0 and x==0):
	t1=np.pi/2
elif(y<0 and x==0):
	t1=-np.pi/2
if(round(np.sin(t1))!=0):
	a=y/np.sin(t1)
else:
	a=x/np.cos(t1)

b=z-a1

if(b==0 and a<0):
	phi=-np.pi/2
elif(b==0 and a>0):
	phi=np.pi/2
elif(round(a,3)<0.002 and b==0):
	phi=0
else:
	phi=np.arctan2(a,b)


r=round(np.sqrt(a*a+b*b),3)

d=round((a*a+b*b+a2*a2-a3*a3)/(2*a2),3)  

if(round(d)==0 and round((r*r-d*d))==0):
	t2phi=0
elif(round(r*r-d*d)==0 and d<0 and y!=0):								##removed all 8 round offs for r2-d2 and sqrt
	t2phi= -np.pi/2              
elif(round((r*r-d*d))==0 and d>0 and y!=0):
	t2phi= +np.pi/2                       #check +-
elif(round((r*r-d*d))==0 and d<0 and y==0):
	t2phi= -np.pi/2              
elif(round((r*r-d*d))==0 and d>0 and y==0):
	t2phi= +np.pi/2   

#t2phi=np.arctan2(d,round(np.sqrt(r*r-d*d)))

elif(y>0):															# checked this +ve and -ve once .......... changed
	t2phi=np.arctan2(d,(-np.sqrt(np.absolute(r*r-d*d))))
elif(y<0):
		t2phi=np.arctan2(d,(np.sqrt(np.absolute(r*r-d*d))))
elif(z>a1):
			t2phi=np.arctan2(d,(np.sqrt(np.absolute(r*r-d*d))))
elif(z<a1):
		t2phi=np.arctan2(d,(-np.sqrt(np.absolute(r*r-d*d))))
else:
		t2phi=np.arctan2(d,(-np.sqrt(np.absolute(r*r-d*d)))) ##########################################################check this sign

t2=t2phi-phi
#t3=np.arccos(a-a2*(np.cos(t2)/a3))-t2         # this must be cos
#oryou can use
"""print((round(b)-round(a2*np.sin(t2),3))/a3)
if((b-a2*np.sin(t2)/a3)<=1 and (b-a2*np.sin(t2)/a3)>=-1):
	t3=np.arcsin((b-a2*np.sin(t2))/a3)-t2
	print(t3)
else:
	t3=np.arccos(a-a2*(np.cos(t2)/a3))-t2
"""
q = round((b-a2*np.sin(t2))/a3,3)
print ("q",q)	
print ("sini",round(((b-a2*np.sin(t2))/a3),3))
print ("cosi",(a-a2*np.cos(t2))/a3)
if((q>=-1) and (q<=1)):	
	m = np.arcsin(q)
	print ("m",m)	
	t3=m-t2
	print ("if",t3)
else:
	t3=np.arccos((a-a2*np.cos(t2))/a3)-t2
	print ("else",t3)
#if(t3==np.pi or t3==(-1)*np.pi):															# checked this +ve and -ve once
#	t3=0
if(t1<-np.pi):											# made -270 to +90S
	t1+=2*np.pi
elif(t1>np.pi):
	t1-=2*np.pi
print(round(np.sin(t1)))
t1=round(t1*180/np.pi)
t2=round(t2*180/np.pi)
t3=round(t3*180/np.pi)

t2phi=round(t2phi*180/np.pi)

phi=round(phi*180/np.pi)
# print(r)
# print(d)   
# print(r*r-d*d)    
# print(a,b)
# print(t2phi,phi)

print (t1,t2,t3)
# print(((b-a2*np.sin(t2))/a3))
"""ser= serial.Serial('/dev/ttyUSB0',baudrate = 9600)
ser.write(t1)
ser.write(t2)
ser.write(t3)"""
#ser.write('%d'%(t1*10+1))
#time.sleep(0.002)
#ser.write('%d'%(t2*10+2))
#time.sleep(0.002)
#ser.write('%d'%(t3*10+3))
#time.sleep(0.002)

