.global main

// Global variables
.data
a: .word 60
b: .word 25

.text

main:

        push {ip, lr}
	
	// Local variables, load in values using two registers each
	
        ldr r2, =a
        ldr r0, [r2]

        ldr r3, =b
        ldr r1, [r3]

	// The while loop compares r0 and r1. It branches down to endwhile
	// on the opposite quality. Otherwise the if statement begins. It branches
	// to else on the opposite quality. Otherwise it will subtract
	// r1 from r0 and branch to done. If else is branched to the it will
	// subtract r1 from r0. Done restarts the while loop and end while
	// allows us to pop and exit with the appropriate values in place. 

        while:
         cmp r0, r1

         beq endwhile

         cmp r0, r1

         ble else

        if:
         sub r0, r0, r1

         b done

        else:
         sub r1, r1, r0

        done:
        b while

        endwhile:


        pop {ip, pc}

