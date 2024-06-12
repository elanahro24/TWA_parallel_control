function [portBit]= mdiostgmodel2(action,channels,port)

if action==1
    initBlock=find_system(bdroot,'FollowLinks','on','LookUnderMasks','all','MaskType', 'initstgmodel2');
    if isempty(initBlock)
        add_block('ServoToGo/Init',[gcs '/Init'],'position',[0 0 30 30],'backgroundcolor','lightblue','debug_flag','off');
    end
else
    
    maskType=get_param(gcb, 'MaskType');
    directionStr= maskType(1:2);
    maskType= maskType(3:end);
    switch directionStr
        case 'di'
            direction=1;
        case 'do'
            direction=2;
    end
    
    %%% check channel parameter
    minChannel=0;maxChannel=7;
    
    if ismember(port,[1 2])
        portBit=bitset(0,port);
    elseif port==3
        portBit=bitset(bitset(0,3),4);
    elseif port==4
        portBit=bitset(bitset(0,5),6);
    end
    
    if ~isnumeric(channels) | min(channels)<minChannel | max(channels)>maxChannel | size(channels,1)>1
        uiwait(errordlg(sprintf('Channel must be a row vector with elements between %d and %d.',minChannel,maxChannel)));
        return;
    end
    channels=round(channels);
    
    selected_channels=[];
    
    for id=1:length(channels)
        if ismember(channels(id),selected_channels)
            uiwait(errordlg(sprintf('Channel %d is already accessed. This introduces unnessecary additonal latency by the drivers.',channels(id))));return;
        else
            selected_channels=[selected_channels,channels(id)];
        end
    end
    
    %disp('hi');
    
    maskDisplay='disp(''Model 2\nServo To Go\n';
    maskDescription=['Model 2',10,'Servo To Go',10];
    
    if direction==1
        %disp('display');
        maskDisplay=[maskDisplay,'Digital Input'');'];
        for i=1:length(channels)
            maskDisplay=[maskDisplay,'port_label(''output'',',num2str(i),',''',num2str(channels(i)),''');'];
        end
        maskDescription= [maskDescription, 'Digital Input'];
    elseif direction==2
        maskDisplay=[maskDisplay,'Digital Output'');'];
        for i=1:length(channels)
            maskDisplay=[maskDisplay,'port_label(''input'',',num2str(i),',''',num2str(channels(i)),''');'];
        end
        maskDescription= [maskDescription, 'Digital Output'];
    end
    
    set_param(gcb, 'MaskDisplay', maskDisplay);
    set_param(gcb, 'MaskDescription', maskDescription);
end
