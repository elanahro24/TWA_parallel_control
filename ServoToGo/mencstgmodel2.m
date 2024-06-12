function mencstgmodel2(action,channels)

if action==1
    initBlock=find_system(bdroot,'FollowLinks','on','LookUnderMasks','all','MaskType', 'initstgmodel2');
    if isempty(initBlock)
        add_block('ServoToGo/Init',[gcs '/Init'],'position',[0 0 30 30],'backgroundcolor','lightblue','debug_flag','off');
    end
else
    
    %%% check channel parameter
    maxChannel=7;
    if ~isnumeric(channels) | min(channels)<0 | max(channels)>maxChannel
        errordlg(sprintf('Channel must be a vector with elements between 0 and %d.',maxChannel));
        return;
    end
    
    
    maskdisplay = 'disp(''Model 2\nServo To Go\nEncoder Input'');';
    for i = 1:length(channels)
        maskdisplay = sprintf('%s port_label(''output'', %i, ''%i''); port_label(''input'', %i, ''%i(RS)'');', maskdisplay, i, channels(i), i, channels(i));
    end         
    maskdescription = ['Model 2' 10 'Servo To Go' 10 'Encoder Input'];
    
    set_param(gcb,'MaskDisplay',maskdisplay);
    set_param(gcb,'MaskDescription',maskdescription);
end