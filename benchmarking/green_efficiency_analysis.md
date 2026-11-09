# Green Tech Efficiency and Benchmarking Analysis

## Measurement Methodology

I ran the supplied C programs in the same sandbox environment. The required compilation flags were -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long. I kept the baseline and comparison algorithms unchanged and added timing instrumentation to the instrumentation program.

Timing used clock() and clock_t from <time.h>. Differences between timestamps were divided by CLOCKS_PER_SEC to obtain seconds. These measurements represent CPU time used by the program, rather than elapsed wall-clock time or electrical energy.

I executed the baseline program three consecutive times and recorded its complete output. I also recorded three runs of the comparison program and calculated arithmetic means. For instrumentation, I recorded one run using four timestamps: before building the dataset, after building, after processing, and after checksum reduction. Adjacent timestamps defined phase durations; the first and last defined TOTAL. Printing occurred outside the measured interval.

## Observed Performance Differences

The baseline performed 100000000 iterations per run. Its measured times were 0.193792, 0.198700, and 0.195481 seconds. The difference between the largest and smallest values was 0.004908 seconds, demonstrating variation despite an unchanged workload.

The naive comparison implementation took 2.358259, 2.353227, and 2.351832 seconds. Its average was approximately 2.354439333 seconds. The single-pass implementation took 0.000091, 0.000092, and 0.000091 seconds, averaging approximately 0.000091333 seconds. Dividing the unrounded averages gives a ratio of approximately 25778.53. Thus, the naive workload used approximately 25,778.53 times as much CPU time in these runs.

However, the outputs were different: the naive result was 625025000, while the single-pass result was 25000. The nested loops repeatedly count even elements in overlapping prefixes. The single-pass version counts each even element once. Consequently, the timing ratio compares different workloads, not interchangeable implementations producing an identical answer.

Instrumentation reported TOTAL as 0.000615 seconds, BUILD_DATA as 0.000240, PROCESS as 0.000259, and REDUCE as 0.000116. PROCESS was the largest measured phase, accounting for approximately 42.1% of TOTAL. The three displayed phase durations sum to the displayed total.

## Relation Between Runtime and Energy Consumption

The comparison demonstrates a substantial difference in measured CPU time. It does not establish a corresponding energy ratio. No power meter, energy counter, or watt measurement was used.

Shorter CPU activity provides a reason to investigate potential energy savings, but these results alone cannot quantify them. Actual energy depends on power consumption during execution as well as duration. I therefore interpret runtime as an efficiency indicator, not proof that one program consumed a specific amount less electricity.

## Limitations of the Experiment

The comparison implementations produce different answers, limiting conclusions about replacing one with the other. The single-pass durations were only 91 to 92 microseconds, making timer resolution and measurement overhead important relative to the measured interval.

Three runs provide limited evidence about variability, and the instrumentation result comes from only one run. Shared phase boundaries consistently partition the total, but clock() calls introduce overhead. The measurements do not isolate that overhead or establish performance on other machines. No direct energy measurements were collected.

## Practical Engineering Takeaway

These results support measuring before choosing an optimization target and checking correctness before comparing speed. PROCESS is a candidate for further investigation because it was the largest phase in the recorded run, but repeated measurements are needed before treating that ordering as stable.

For future changes, I would preserve inputs, compiler settings, and environment, verify equivalent outputs, and repeat measurements. Any sustainability conclusion should distinguish demonstrated CPU-time changes from energy savings that still require direct validation.
