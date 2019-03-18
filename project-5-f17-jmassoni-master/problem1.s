.global main

// Global variables
.data
a: .word 10
b: .word 20
c: .word 30

.text

main:
        push {ip, lr}

	// Local Variables loaded into one register
	// Then use another register to point to the value

        ldr r3, =a
        ldr r0, [r3]

        ldr r4, =b
        ldr r1, [r4]

        ldr r5, =c
        ldr r2, [r5]
	
	// Sum is stored in r6 and the addition
	// is done one register at a time
	// This is the equivalent is r6 += r1
	// in high level languages

        add r6, r0, r1
        add r6, r6, r2
	
	// I used multiple registers to avoid any accidental
	// overwriting. Here I move the sum into r0 as the final
	// output

        mov r0, r6

        pop {ip, pc}