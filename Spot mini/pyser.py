import serial
import time
ser=serial.Serial('/dev/ttyUSB1', baudrate=9600)
"""def getvalues():
	my.write(b'g')
	arduinodata=ser.readline().decode('ascii')
	return arduinodata
"""
while(1):
	print("Press c")
	userinput = raw_input()
	if userinput == 'c':
		ser.write('c')
		print("Led turned on")
		#time.sleep(1)
	if userinput != 'c':
		# ser.write('d')
		print("Led turned off")
		#time.sleep(1)
	# try:
	# 	ser.flush()
	# 	msg = ser.readline()
	# 	print("Message Received : ",msg)
	# except:
	# 	pass
		# print(getvalues())