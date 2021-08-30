## VUESIN.
### Used to test an ESIN implementation on VU1

The PS2 VU documentation states that ESIN is valid for x between -π / 2 and +π / 2

It also states that the approximation formula is such:

![image](https://user-images.githubusercontent.com/29295048/131409447-bc123a7b-47f5-40b1-9cdb-f2877ea10f5e.png)

Here is a visual representation of the formula compared against sin(x)

![image](https://user-images.githubusercontent.com/29295048/131409664-6658ae20-5368-4b8e-a2e9-9f8e94b0653f.png)


## Example:

`VF01x` is `x`

`VF01y` is `ESIN x`

A VU ESIN implementation that is std::sin(x)
```
[iter 0] [VF01x -5.000000] [VFO1y 0.958924]
[iter 1] [VF01x -4.500000] [VFO1y 0.977530]
[iter 2] [VF01x -4.000000] [VFO1y 0.756802]
[iter 3] [VF01x -3.500000] [VFO1y 0.350783]
[iter 4] [VF01x -3.000000] [VFO1y -0.141120]
[iter 5] [VF01x -2.500000] [VFO1y -0.598472]
[iter 6] [VF01x -2.000000] [VFO1y -0.909297]
[iter 7] [VF01x -1.500000] [VFO1y -0.997495]
[iter 8] [VF01x -1.000000] [VFO1y -0.841471]
[iter 9] [VF01x -0.500000] [VFO1y -0.479426]
[iter 10] [VF01x 0.000000] [VFO1y 0.000000]
[iter 11] [VF01x 0.500000] [VFO1y 0.479426]
[iter 12] [VF01x 1.000000] [VFO1y 0.841471]
[iter 13] [VF01x 1.500000] [VFO1y 0.997495]
[iter 14] [VF01x 2.000000] [VFO1y 0.909297]
[iter 15] [VF01x 2.500000] [VFO1y 0.598472]
[iter 16] [VF01x 3.000000] [VFO1y 0.141120]
[iter 17] [VF01x 3.500000] [VFO1y -0.350783]
[iter 18] [VF01x 4.000000] [VFO1y -0.756802]
[iter 19] [VF01x 4.500000] [VFO1y -0.977530]
```

The test run on real hardware

```
[iter 0] [VF01x -5.000000] [VFO1y 0.185349]
[iter 1] [VF01x -4.500000] [VFO1y 0.743344]
[iter 2] [VF01x -4.000000] [VFO1y 0.696820]
[iter 3] [VF01x -3.500000] [VFO1y 0.338494]
[iter 4] [VF01x -3.000000] [VFO1y -0.142953]
[iter 5] [VF01x -2.500000] [VFO1y -0.598637]
[iter 6] [VF01x -2.000000] [VFO1y -0.909303]
[iter 7] [VF01x -1.500000] [VFO1y -0.997495]
[iter 8] [VF01x -1.000000] [VFO1y -0.841471]
[iter 9] [VF01x -0.500000] [VFO1y -0.479426]
[iter 10] [VF01x 0.000000] [VFO1y 0.000000]
[iter 11] [VF01x 0.500000] [VFO1y 0.479426]
[iter 12] [VF01x 1.000000] [VFO1y 0.841471]
[iter 13] [VF01x 1.500000] [VFO1y 0.997495]
[iter 14] [VF01x 2.000000] [VFO1y 0.909303]
[iter 15] [VF01x 2.500000] [VFO1y 0.598637]
[iter 16] [VF01x 3.000000] [VFO1y 0.142953]
[iter 17] [VF01x 3.500000] [VFO1y -0.338494]
[iter 18] [VF01x 4.000000] [VFO1y -0.696820]
[iter 19] [VF01x 4.500000] [VFO1y -0.743344]
```
