all: cpu1 cpu2 cpu4process cpu4thread cpu5 pipeoverhead


cpu1:
	gcc -Isrc/lib -o cpu1.out src/cpu/part1/cpu1.c

cpu2:
	gcc -Isrc/lib -w -o cpu2_0.out src/cpu/part2/pco0.c
	gcc -Isrc/lib -w -o cpu2_1.out src/cpu/part2/pco1.c
	gcc -Isrc/lib -w -o cpu2_2.out src/cpu/part2/pco2.c
	gcc -Isrc/lib -w -o cpu2_3.out src/cpu/part2/pco3.c
	gcc -Isrc/lib -w -o cpu2_4.out src/cpu/part2/pco4.c
	gcc -Isrc/lib -w -o cpu2_5.out src/cpu/part2/pco5.c
	gcc -Isrc/lib -w -o cpu2_6.out src/cpu/part2/pco6.c
	gcc -Isrc/lib -w -o cpu2_7.out src/cpu/part2/pco7.c

cpu4process:
	gcc -Isrc/lib -o cpu4process.out src/cpu/part4/cpu4_process.c

cpu4thread:
	gcc -Isrc/lib -o cpu4thread.out -pthread src/cpu/part4/cpu4_thread.c

cpu5:
	gcc -Isrc/lib -o cpu5.out src/cpu/part5/cpu5_simple.c

pipeoverhead:
	gcc -Isrc/lib -o pipeoverhead.out src/cpu/part5/pipe_overhead.c

clean:
	rm *.out
