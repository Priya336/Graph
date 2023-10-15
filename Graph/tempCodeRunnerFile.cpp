        if(child!=i){
      int a= dfs(child,i);
      sum=0;
      int b= dfs(i,child);
      sum=0;
     int c=a*b;
      m[c]={i,child};
     
       cout<<a<<b<<" "<<c<<"  "<<i<<" "<<child<<endl;