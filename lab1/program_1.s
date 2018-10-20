		.data
values: .word 	7,17,8,5,16,12,1,14,0,15,4,15,6,22,9,10,2,3,18,13
		.word	7,17,8,5,16,12,1,14,0,15,4,15,6,22,9,10,2,3,18,13
		.word	7,17,8,5,16,12,1,14,0,15,4,15,6,22,9,10,2,3,18,13
		.word	7,17,8,5,16,12,1,14,0,15,4,15,6,22,9,50,2,3,18,13
		.word	99,17,8,5,16,12,1,14,0,15,4,15,6,22,9,10,2,3,18,13
result: .space 8
		
		.text
MAIN: 	daddui 	R1,R0,800;    	numero di iterazioni
		dadd	R2,R0,R0;		contatore
		ld		R4,values(R2);	tiene il massimo

LOOP:	daddui	R2,R2,8						;incremento il contatore
		slt		R5,R2,R1					;se R2<800 R5=1
		beqz	R5,ENDING					;se R5 =1 -> salto alla fine
		ld		R3,values(R2)
		
		slt		R5,R4,R3					;se il valore corrente è minore del massimo R5=1
		beqz	R5,LOOP						;se R5 =1 salto al prossimo elemento del vettore
		movz	R4,R3,R0					;aggiorno il massimo con il nuovo valore
		beqz	R0,LOOP						;salto al prossimo numero

ENDING:	sd		R4,result(R0)				;salvo 

HALT
