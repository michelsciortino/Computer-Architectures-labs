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
MAIN:	daddui R1,R0,25
		dadd R2,R0,R0
LOOP:	l.d F11,v1(R2)			;first
		l.d F12,v2(R2)
		daddi R1,R1,-1
		mul.d F13,F11,F12
		s.d F13,v3(R2)
		div.d F14,F13,F12
		s.d F14,v4(R2)
		add.d F15,F14,F12
		s.d F15,v5(R2)
		daddi R2,R2,8
		l.d F11,v1(R2)			;second
		l.d F12,v2(R2)
		mul.d F13,F11,F12
		s.d F13,v3(R2)
		div.d F14,F13,F12
		s.d F14,v4(R2)
		add.d F15,F14,F12
		s.d F15,v5(R2)
		daddi R2,R2,8
		l.d F11,v1(R2)			;third
		l.d F12,v2(R2)
		mul.d F13,F11,F12
		s.d F13,v3(R2)
		div.d F14,F13,F12
		s.d F14,v4(R2)
		add.d F15,F14,F12
		s.d F15,v5(R2)
		daddi R2,R2,8
		l.d F11,v1(R2)			;fourth
		l.d F12,v2(R2)
		mul.d F13,F11,F12
		s.d F13,v3(R2)
		div.d F14,F13,F12
		s.d F14,v4(R2)
		add.d F15,F14,F12
		s.d F15,v5(R2)
		daddi R2,R2,8
		bnez R1,LOOP
nop
halt