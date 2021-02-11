%{
int mgh=0;
int msh=0;
%}

%%
gy ++msh;
cs ++msh;
dz ++msh;
ly ++msh;
dzs ++msh;
zs ++msh;
sz ++msh;
ny ++msh;
ty ++msh;
[a,e,i,o,u] ++mgh;
[b,c,d,f,g,h,j,k,l,m,n,p,q,r,s,t,v,w,x,y,z] ++msh;

end return 0;

%%

int main(){


yylex();
printf("\nMassalhangzok szama a szovegben: %d\n", msh);
printf("\nMaganhangzok szama a szovegben: %d\n", mgh);
return 0;
}
