close all;
W=0:0.1:10;
des_RPM_L=[];
des_RPM_R=[];
Vr=[];
Vl=[];
for i = 1:size(W,2)
    [des_RPM_R(i),des_RPM_L(i),Vr(i),Vl(i)]=set_desRPM(0,W(i),0.25,0.08);
end
plot(W,des_RPM_R,W,des_RPM_L);
title('desired RPM vs W con V=0');
legend('desired RPM Right','desired RPM Left');
ylabel('desired RPM');
xlabel('W(rad/s)');
figure();
plot(W,Vr,W,Vl);
title('desired Vr,Vl vs W con V=0');
legend('desired Vr(m/s)','desired Vl(m/s)');
ylabel('desired V(m/s)');
xlabel('W(rad/s)');

V=0:0.1:10;
des_RPM_L=[];
des_RPM_R=[];
for i = 1:size(W,2)
    [des_RPM_R(i),des_RPM_L(i),Vr(i),Vl(i)]=set_desRPM(V(i),0,0.25,0.08);
end
figure;
plot(V,des_RPM_R,V,des_RPM_L);
title('desired RPM vs V con W=0');
legend('desired RPM Right','desired RPM Left');
ylabel('desired RPM');
xlabel('V(m/s)');
figure();
plot(V,Vr,V,Vl);
title('desired Vr,Vl vs V con W=0');
legend('desired Vr(m/s)','desired Vl(m/s)');
ylabel('desired V(m/s)');
xlabel('V(m/s)');