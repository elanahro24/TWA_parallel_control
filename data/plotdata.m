close all;
clear;

load('data0910_1.mat')
% plot joint positions
fig1 = figure();

hold on
q_vec = qvec.data;
vecsize = size(q_vec);

for i = 1:(vecsize(2)-1);plot(q_vec(:,vecsize(2)),q_vec(:,i),'linewidth',2.5); end

ax1 = fig1.Children;
fig1.Color = 'white';
ax1.XLabel.String = 'Time [s]';
ax1.XLabel.FontSize = 15;
ax1.XLabel.Interpreter = 'latex';
ax1.YLabel.String = 'Position [mm]';
ax1.YLabel.FontSize = 15;
ax1.YLabel.Interpreter = 'latex';
ax1.Title.String = 'Joint Positions with Redundancy Resolution';
ax1.Title.Interpreter = 'latex';
ax1.Title.FontSize = 20;

ax1.XGrid = 'on';
ax1.YGrid = 'on';

lgd = legend();
lgd.String = {'VLMX_1' 'VLMX_2' 'VLMX_3' 'TWA_1' 'TWA_2' 'TWA_3'};
lgd.NumColumns = 2;
lgd.FontSize = 11;

% Plot EE Position
fig2 = figure();
hold on
x_vec = xvec.data;

vecsize = size(x_vec);

plot(x_vec(:,vecsize(2)),x_vec(:,1),'linewidth',2.5);
plot(x_vec(:,vecsize(2)),x_vec(:,2),'linewidth',2.5);


ax2 = fig2.Children;
fig2.Color = 'white';
ax2.XLabel.String = 'Time [s]';
ax2.XLabel.FontSize = 15;
ax2.XLabel.Interpreter = 'latex';
ax2.YLabel.String = 'Position [mm]';
ax2.YLabel.FontSize = 15;
ax2.YLabel.Interpreter = 'latex';
ax2.Title.String = 'End Effector Position [$$\mathbf{x} = \dot{\mathbf{x}}\mathrm{dt}$$]';
ax2.Title.Interpreter = 'latex';
ax2.Title.FontSize = 20;

ax2.XGrid = 'on';
ax2.YGrid = 'on';

lgd = legend();
lgd.String = {'x' 'y'};
lgd.Orientation = 'horizontal';
lgd.FontSize = 11;

% Plot delta q
% fig3 = figure();
% hold on
% qdel_vec = qdel.data;
% vecsize = size(qdel_vec);
% 
% for i = 1:vecsize(2)-1
%     subplot(vecsize(2)-1,1,i); 
%     plot(qdel_vec(:,vecsize(2)),qdel_vec(:,i),'linewidth',2.5); 
% end
% fig3.Color = 'white';
% ax3 = fig3.Children;
% 
% ax3(6,1).Title.String = 'Joint Length Increment';
% ax3(6,1).Title.Interpreter = 'latex';
% ax3(6,1).Title.FontSize = 20;
% 
% ax3(1,1).XLabel.String = 'Time [s]';
% ax3(1,1).XLabel.FontSize = 15;
% 
% for i = 1:(vecsize(2)-1)
%     str = ['$\Delta q_{',num2str(i),'}$'];
%     ax3(i,1).YLabel.Interpreter= 'latex';
%     ax3(i,1).YLabel.String = str;
%     ax3(i,1).YLabel.FontSize = 15;
%     ax3(i,1).XLim = [55 160];
%     ax3(i,1).XGrid = 'on'
% end
