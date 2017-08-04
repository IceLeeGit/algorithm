# algorithm
This project is set of some algorithms.


1. Hanoi Algorithm
   Describe the non-recursive function:
   
   procedure hanoi(n)
   
    i <- 0;
    if n%2==0 then
        x <- 0;   
    else
        x <- 1;
        
    repeat 
    
        forward = (A+i-x+2)%3       
        mid = (A+i)%3 
        back = (A+i+1+x)%3
        
        if back is NULL then
            back <- mid.pop
            
        else if back > mid then
            back <- A=mid.pop

        if mid is NULL then
            mid <- forward;

        if forward is NULL then
            forward <- mid.pop
        else if forward > mid then
            forward <- mid.pop

        i <- i + x +1; 
        
    until C.len == n 
        
