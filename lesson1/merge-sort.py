
import math
import sys
def merge(A,p,q,r):
    A1 = A[p:q]
    A2 = A[q:r]
   
    A1.append(sys.maxsize)
    A2.append(sys.maxsize)
    print(A1, A2)
    i = p 
    j = 0
    k = 0
    while (j + k < len(A1) + len(A2) - 2):
        if (A1[j] < A2[k]):
            A[i] = A1[j]
            j = j+1
        else:
            A[i] = A2[k]
            k= k+1
        i= i +1
    print(A[p:r], "merge后")

def merge_sort(A,p,r):
    if(r - p == 1):
        return
    if(p == r):
        return
    q = math.floor((p+r)/2)
    merge_sort(A, p, q)
    merge_sort(A, q, r)
    merge(A,p,q,r)
if __name__ == "__main__":
    a = [2,3,1,44,22,15,9]
    merge_sort(a, 0, len(a))
    print(a)


