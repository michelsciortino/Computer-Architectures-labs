	.data
v1: .space 800
v2: .double 1 2 3 4 5 6 7 8 9 10
    .double 1 2 3 4 5 6 7 8 9 10
    .double 1 2 3 4 5 6 7 8 9 10
    .double 1 2 3 4 5 6 7 8 9 10
    .double 1 2 3 4 5 6 7 8 9 10
    .double 1 2 3 4 5 6 7 8 9 10
    .double 1 2 3 4 5 6 7 8 9 10
    .double 1 2 3 4 5 6 7 8 9 10
    .double 1 2 3 4 5 6 7 8 9 10
    .double 1 2 3 4 5 6 7 8 9 10
v3: .space 800
v4: .space 800
v5: .space 800
	.text
MAIN:	daddui R1,R0,100
	dadd R2,R0,R0
LOOP:
	l.d F11,v1(r2)
	l.d F12,v2(r2)
	daddi R1,R1,-1
	mul.d F13,F11,F12;v1[i]*v2[i]	
	s.d F13,v3(r2)
	div.d F14,F13,F12
	s.d F14,v4(r2)
	add.d F15,F14,F12
	s.d F15,v5(r2)
	daddi R2,R2,8
	bnez R1,LOOP	
halt