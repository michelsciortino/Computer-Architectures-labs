	.data
v: .space 100
	.text 
MAIN:	daddi r1,r0,100
	daddi r2,r0,0
LOOP:	daddi r3,r0,0
	lb r5,v(r2)
	andi r4,r5,2
	dadd r3,r3,r4
	andi r4,r5,4
	dadd r3,r3,r4
	andi r4,r5,8
	dadd r3,r3,r4
	andi r4,r5,16
	dadd r3,r3,r4
	andi r4,r5,32
	dadd r3,r3,r4
	andi r4,r5,64
	dadd r3,r3,r4
	andi r4,r5,128
	dadd r3,r3,r4
	andi r4,r4,1
	andi r5,r5,254
	dadd r5,r5,r4
	sb r5,v(r2)
	daddi r2,r2,1
	daddi r1,r1,-1
	bnez r1,LOOP
halt	