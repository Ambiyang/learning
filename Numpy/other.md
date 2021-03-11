a = np.random.random((3,4))  
np.where(a>0.5)  
a[(a>0.3)&(a<0.7)]

### select 
#### 1d index  
a[np.array([3,5,7])]  
#### 2d index  
a[np.array([3,5,7],[3,5,7])]

a = np.array([4,6,4,8,5])  
a[::2] *= a[::2]  
a
[16,6,16,8,25]

#### any calculate with np.nan will result to np.nan

