.global main


main:

        push {ip, lr}
	
	// Local variables, the actual numbers are placed
	// directly into the registers

        mov r0, #10
        mov r1, #5
        mov r2, #20

	// I'm using r3 to represent max and to avoid
	// accidentally overwriting r0

        mov r3, r0

	
	// The next few lines compare y and x
	// The ble, if true, will skip changing max
	// The mov will overwrite the value in max with y

        cmp r1, r3

        ble body

        mov r3, r1

	// This is a similar if statement
	// body and done are labeled to allow
	// for proper circumvention of the max modifiers
	
        body:
         cmp r2, r3

         ble done

         mov r3, r2

	// Done just moves max back into r0 so it can be popped
	
        done:
         mov r0, r3

        pop {ip, pc}