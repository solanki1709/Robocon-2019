import serial
ser=serial.Serial('/dev/ttyUSB3',9600)
userInput = 0
while(1):
	print("Enter 324")
	userInput=324
	# userInput = raw_input()
	print("userinput is ")
	print userInput
	if userInput == 324 :
		ser.write(userInput)
		print("Led turned on")
	else:
		print("Batti gul")