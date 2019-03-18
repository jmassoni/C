.global main

//Global variables

.data
fib: .word 1
prev: .word 0

.text

main:
        push {ip, lr}

	// Loading global variable values into local variables	

        ldr r2, =fib
        ldr r0, [r2]

        ldr r3, =prev
        ldr r1, [r3]

	// Here numbers are directly loaded into local variables
	// (registers)

        mov r4, #1
        mov r5, #0


	// The while loop is used to see whether n (r4) is less than
	// or equal to 10. The bgt line branches on the opposite quality.
	// Then I use add and mov to finish the arithmetic.
	// The b while loops back through the while loop. And endwhile
	// allows us to pop once the while condition is false.

        while:
         cmp r4, #10

         bgt endwhile

         add r5, r0, r1
         mov r1, r0
         mov r0, r5
         add r4, r4, #1

        b while

        endwhile:



        pop {ip, pc}
