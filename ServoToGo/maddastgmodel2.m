function maddastgmodel2(action,channels)

if action==1
    initBlock=find_system(bdroot,'FollowLinks','on','LookUnderMasks','all','MaskType', 'initstgmodel2');
    if isempty(initBlock)
        add_block('ServoToGo/Init',[gcs '/Init'],'position',[0 0 30 30],'backgroundcolor','lightblue','debug_flag','off');
    end
else
    
    %disp('hi');
    
    %%% check channel parameter
    maxChannel=7;
    if ~isnumeric(channels) | min(channels)<0 | max(channels)>maxChannel
        errordlg(sprintf('Channel must be a vector with elements between 0 and %d.',maxChannel));
        return;
    end
    
    maskType=get_param(gcb, 'MaskType');
    directionStr= maskType(1:2);
    maskType= maskType(3:end);
    switch directionStr
        case 'ad'
            direction=1;
        case 'da'
            direction=2;
    end
    
    maskdisplay = 'disp(''Model 2\nServo To Go\n';
    if direction == 1
        maskdisplay = [maskdisplay 'Analog Input'');'];
        for i = 1:length(channels)
            maskdisplay = sprintf('%s port_label(''output'', %i, ''%i'');', maskdisplay, i, channels(i));
        end         
        maskdescription = ['Model 2' 10 'Servo To Go' 10 'Analog Input'];
    else
        maskdisplay = [maskdisplay 'Analog Output'');'];
        for i = 1:length(channels)
            maskdisplay = sprintf('%s port_label(''input'', %i, ''%i'');', maskdisplay, i, channels(i));
        end         
        maskdescription = ['Model 2' 10 'Servo To Go' 10 'Analog Output'];
    end
    
    set_param(gcb,'MaskDisplay',maskdisplay);
    set_param(gcb,'MaskDescription',maskdescription);
end