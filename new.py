def square_matrix(n):
    num=i.count(1)
    l=[[next(num) for i in range(n)]for j in range(n)]
    return l
def form_required_matrix(n):
    l=square_matrix(n)
    if(n%2!=0):
        for i in range(0,n):
            if(i%2!=0):
                l[i][:]=l[i][::-1]
    for i in range(0,n):
        print(l[i])
form_required_matrix(5)