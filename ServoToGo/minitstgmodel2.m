function varargout = minitstgmodel2(action, sampleTime, baseHex, debug_flag, irq_num);

if action==1
    diBlocks=find_system(bdroot,'FollowLinks','on','LookUnderMasks','all','MaskType', 'distgmodel2');
    doBlocks=find_system(bdroot,'FollowLinks','on','LookUnderMasks','all','MaskType', 'dostgmodel2');
    adBlocks=find_system(bdroot,'FollowLinks','on','LookUnderMasks','all','MaskType', 'adstgmodel2');
    daBlocks=find_system(bdroot,'FollowLinks','on','LookUnderMasks','all','MaskType', 'dastgmodel2');
    
    dimaskValues=get_param(diBlocks,'MaskValues');dimaskValues=horzcat(dimaskValues{:});
    domaskValues=get_param(doBlocks,'MaskValues');domaskValues=horzcat(domaskValues{:});
    admaskValues=get_param(adBlocks,'MaskValues');admaskValues=horzcat(admaskValues{:});
    damaskValues=get_param(daBlocks,'MaskValues');damaskValues=horzcat(damaskValues{:});
    
    if isempty(dimaskValues);dimaskValues=cell(3,0);end;
    if isempty(domaskValues);domaskValues=cell(3,0);end;
    if isempty(admaskValues);admaskValues=cell(2,0);end;
    if isempty(damaskValues);damaskValues=cell(2,0);end;
    
    %check digital i/o
    diPorts=unique(dimaskValues(2,:));
    doPorts=unique(domaskValues(2,:));
    if ~isempty(intersect(diPorts,doPorts))
        uiwait(errordlg('There is a port defined as both digital input and output'));
        set_param(gcs,'SimulationCommand','stop');return;
    end
    
    all_ports={'A','B','C','D'};
    dio_direction=zeros(4,8);
    %check digital input channels
    if ~isempty(dimaskValues)
        for id=1:size(dimaskValues,2)
            portID=strmatch(dimaskValues{2,id},all_ports);
            if any(dio_direction(portID,eval(dimaskValues{1,id})+1))
                uiwait(errordlg(sprintf('There is a channel redundancy in Port %s',dimaskValues{2,id})));
                set_param(gcs,'SimulationCommand','stop');return;
            else
                dio_direction(portID,eval(dimaskValues{1,id})+1)=1;
            end
        end
    end
    %check digital output channels
    if ~isempty(domaskValues)
        for id=1:size(domaskValues,2)
            portID=strmatch(domaskValues{2,id},all_ports);
            if any(dio_direction(portID,eval(domaskValues{1,id})+1))
                uiwait(errordlg(sprintf('There is a channel redundancy in Port %s',domaskValues{2,id})));
                set_param(gcs,'SimulationCommand','stop');return;
            else
                dio_direction(portID,eval(domaskValues{1,id})+1)=1;
            end
        end
    end
    
else
    %%% check sampleTime parameter
    if ~isa(sampleTime, 'double') | max(size(sampleTime))>1
        uiwait(errordlg('Sample Time parameter must be of class double'));
        return;
    end
    
    %%% check baseHex parameter
    baseMsg = sprintf('Base address parameter must be of the form ''0xddd'', where ddd is one of the hex addresses 200, 220, 240, ... 3E0\n');
    
    if ~isa(baseHex, 'char')
        uiwait(errordlg([baseMsg '(1)']));
        return;
    end
    
    if length(baseHex) ~= 5 | baseHex(1:2) ~= '0x'
        %disp(baseMsg);
        uiwait(errordlg([baseMsg '(2)']));
        return;
    end
    
    try
        baseDec = hex2dec(baseHex(3:end));
    catch
        uiwait(errordlg([baseMsg '(3)']));
        return;
    end
    
    minBase = hex2dec('200');
    maxBase = hex2dec('3e0');
    incBase = hex2dec('020');
    
    if baseDec < minBase | baseDec > maxBase | mod(baseDec, incBase) ~= 0
        uiwait(errordlg([baseMsg '(4)']));
        return;
    end
    varargout{1}=baseDec;
    
    if ~isnumeric(irq_num)
        uiwait(errordlg('IRQ must be an integer'));
        return;
    end
    
    maskdisplay = 'disp(''STG\n(Init)'');';
    if debug_flag
        port_labels={'wBaseAddress','wIrq','wModel','wNoBoardFlag','wAxesInSys','wSaveDirs'};
        for i=1:length(port_labels)
            maskdisplay=sprintf('%s port_label(''output'', %i, ''%s'');',maskdisplay,i,port_labels{i});
        end
    end
    set_param(gcb,'MaskDisplay',maskdisplay);
end
