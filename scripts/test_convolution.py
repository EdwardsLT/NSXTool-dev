from __future__ import print_function, division
import numpy
from scipy import signal

def extend_kernel(kernel, nrows, ncols):
    nr, nc = kernel.shape
    r0 = int(nr/2)
    c0 = int(nc/2)
    
    extended = numpy.zeros(shape=(nrows, ncols), dtype=float)
    
    extended[:nr, :nc] = kernel
    extended = numpy.roll(extended, -r0, axis=0)
    extended = numpy.roll(extended, -c0, axis=1)
    
    return extended

def sym_pad(arr, pad_row, pad_col):
    
    m = int(max(pad_row,pad_col))

    a = numpy.pad(arr,m,mode="symmetric")

    new_nrows,new_ncols = a.shape

    d = pad_col - pad_row
    cut_row = max(d,0)
    cut_col = max(-d,0)

    padded_a = a[cut_row:new_nrows-cut_row,cut_col:new_ncols-cut_col]

    return padded_a

if __name__ == "__main__":

    a = numpy.array([[ 1,  2,  3,  4, 5, 7],
                     [ 5,  6,  7,  8, 9, 10],
                     [ 9, 10, 11, 12, 11, 12],
                     [13, 14, 15, 16,14,15]])

    k = numpy.array([[3,4,2],[1,7,3],[5,4,3]])
    pad_row = int(k.shape[0]/2)
    pad_col = int(k.shape[1]/2)

    old_nrows,old_ncols = a.shape

    new_nrows = old_nrows + 2*pad_row
    new_ncols = old_ncols + 2*pad_col

    k_ext = extend_kernel(k, new_nrows, new_ncols)

    a_sym = sym_pad(a, pad_row,pad_col)
    nr, nc = a_sym.shape

    a_ft = numpy.fft.fft2(a_sym)
    k_ft = numpy.fft.fft2(k_ext)

    ak_ft = a_ft*k_ft
    ak = numpy.fft.ifft2(ak_ft)

    cr = 0 if k.shape[0] % 2 else 1
    cc = 0 if k.shape[1] % 2 else 1

    print ("symmetrized a")
    print (a_sym)
    print ("kernel")
    print (k)
    print ("extended kernel")
    print (k_ext)
    print(numpy.real(ak))
    print(numpy.real(ak)[pad_row-cr:new_nrows-pad_row-cr, pad_col-cc:new_ncols-pad_col-cc])
    print(signal.convolve2d(a, k, mode="same", boundary="symm"))


# In[ ]:




