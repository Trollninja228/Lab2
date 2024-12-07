int n1,n2;

    n1=g.dijikstra(v[0],v[1])+g.dijikstra(v[1],v[2])+g.dijikstra(v[2],v[3]);
    n2=g.dijikstra(v[0],v[2])+g.dijikstra(v[2],v[1])+g.dijikstra(v[1],v[3]);

    cout<<g.dijikstra(v[0],v[1])<<" "<<g.dijikstra(v[1],v[2])<<" "<<g.dijikstra(v[2],v[3])<<" "<<endl;
    cout<<g.dijikstra(v[0],v[2])<<" "<<g.dijikstra(v[2],v[1])<<" "<<g.dijikstra(v[1],v[3])<<" "<<endl;