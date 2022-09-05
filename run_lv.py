import lv
import numpy as np
import matplotlib.pyplot as plt

# Create the model.

E = lv.LotkaVolterra(0.7, 0.5, 0.3, 0.2, 1.0, 0.5, 0.001, 100.0)

# Set up the model so that we output three single dimension arrays.

n = E.dim_singles()

dbl_t = np.zeros(n, dtype=np.double)
dbl_x = np.zeros(n, dtype=np.double)
dbl_y = np.zeros(n, dtype=np.double)

E.run_singles(dbl_t, dbl_x, dbl_y)

fig1, ax1 = plt.subplots()
ax1.plot(dbl_t, dbl_x)
ax1.plot(dbl_t, dbl_y)
fig1.savefig("output1.pdf")

# Set up the model so that we output one m x n dimension arrays.

length, width = E.dim_combi()

out = np.zeros((length, width), dtype=np.double)

E.run_combi(out)

fig2, ax2 = plt.subplots()
ax2.plot(out[:,0], out[:,1])
ax2.plot(out[:,0], out[:,2])
fig2.savefig("output2.pdf")


