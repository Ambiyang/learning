def kmeans(ds,k):
  m,n=ds.shape
  result=np.empty(m,dtype=np.int)
  cores=ds[np.random.choice(np.arange(m),k,replace=Flase)]
  
  while True:
    d = np.square(np.repeat(ds,k,axis=0).reshape(m,k,n) - cores)
    distance = np.sqrt(np.sum(d,axis = 2))
    index_min = np.argmin(distance,axis=1)
    
    if (index_min = result).all():
      return result,cores
    
    result[:] = index_min
    for i in range(k):
      items = ds[result == i]
      cores[i] = np.mean(items,axis = 0)
    
