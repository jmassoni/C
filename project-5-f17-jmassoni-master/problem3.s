.global main

// Global variables
.data
a: .word 4
b: .word 30

.text

main:

        push {ip, lr}

	// Local variables, values are loaded using
	// secondary registers

        ldr r2, =a
        ldr r0, [r2]

        ldr r3, =b
        ldr r1, [r3]

	// While is labeled and compares the two variables
	// If r0 is larger than or equal to r1 the while loop is exited
	// If no the while loop is restarted
	// Within the while loop the remainder would be passed in
	// remainder - divisor	

        while:
         cmp r0, r1

         blt endwhile

         sub r0, r0, r1

        b while

	// Because r0 is used for the remainder it will inevitably
	// hold the correct value after the while loop is exited	

        endwhile:


        pop {ip, pc}