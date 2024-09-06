function varargout = GUIMAIN(varargin)
% GUIMAIN M-file for GUIMAIN.fig
%      GUIMAIN, by itself, creates a new GUIMAIN or raises the existing
%      singleton*.
%
%      H = GUIMAIN returns the handle to a new GUIMAIN or the handle to
%      the existing singleton*.
%
%      GUIMAIN('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUIMAIN.M with the given input arguments.
%
%      GUIMAIN('Property','Value',...) creates a new GUIMAIN or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUIMAIN_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUIMAIN_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUIMAIN

% Last Modified by GUIDE v2.5 05-Sep-2024 19:17:02

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUIMAIN_OpeningFcn, ...
                   'gui_OutputFcn',  @GUIMAIN_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUIMAIN is made visible.
function GUIMAIN_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUIMAIN (see VARARGIN)

% Choose default command line output for GUIMAIN
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes GUIMAIN wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUIMAIN_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in connect_target.
function connect_target_Callback(hObject, eventdata, handles)
% hObject    handle to connect_target (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fprintf('[\bAttempting to Connect to Target... ]\b\n');

%Connect to target and add slrt class to the handles accessible to gui
target = slrt;
connected = char(target.Connected);

if all(connected == 'Yes')
    fprintf('Succesfully Connected to Target!\n');
elseif all(connected == 'No')
    fprintf(2,'Unsuccesfull Connection to Target!\n');
end

handles.tg = slrt;


% Update handles structure
guidata(hObject, handles);  


% --- Executes on button press in load_model.
function load_model_Callback(hObject, eventdata, handles)
% hObject    handle to load_model (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.tg.load('twa_parallel_pc104');


% --- Executes on button press in start_button.
function start_button_Callback(hObject, eventdata, handles)
% hObject    handle to start_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.tg.start;


% --- Executes on button press in stop_button.
function stop_button_Callback(hObject, eventdata, handles)
% hObject    handle to stop_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.tg.stop;


% --- Executes on button press in enable_jnt_quintic.
function enable_jnt_quintic_Callback(hObject, eventdata, handles)
% hObject    handle to enable_jnt_quintic (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of enable_jnt_quintic
enable_quintic = get(hObject,'Value');

if enable_quintic
    tf = get(handles.quintic_tf,'Value');
    setquintictf(handles.tg,tf);
end

enablequintic(handles.tg,enable_quintic);



function quintic_tf_Callback(hObject, eventdata, handles)
% hObject    handle to quintic_tf (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of quintic_tf as text
%        str2double(get(hObject,'String')) returns contents of quintic_tf as a double
tf = str2double(get(hObject,'String'));
set(hObject,'Value',tf);
setquintictf(handles.tg,tf);

% --- Executes during object creation, after setting all properties.
function quintic_tf_CreateFcn(hObject, eventdata, handles)
% hObject    handle to quintic_tf (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function q1value_Callback(hObject, eventdata, handles)
% hObject    handle to q1value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of q1value as text
%        str2double(get(hObject,'String')) returns contents of q1value as a double
q = str2double(get(hObject,'String'));
set(hObject,'Value',q);

% --- Executes during object creation, after setting all properties.
function q1value_CreateFcn(hObject, eventdata, handles)
% hObject    handle to q1value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function q2value_Callback(hObject, eventdata, handles)
% hObject    handle to q2value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of q2value as text
%        str2double(get(hObject,'String')) returns contents of q2value as a double
q = str2double(get(hObject,'String'));
set(hObject,'Value',q);

% --- Executes during object creation, after setting all properties.
function q2value_CreateFcn(hObject, eventdata, handles)
% hObject    handle to q2value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function q3value_Callback(hObject, eventdata, handles)
% hObject    handle to q3value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of q3value as text
%        str2double(get(hObject,'String')) returns contents of q3value as a double
q = str2double(get(hObject,'String'));
set(hObject,'Value',q);

% --- Executes during object creation, after setting all properties.
function q3value_CreateFcn(hObject, eventdata, handles)
% hObject    handle to q3value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function q4value_Callback(hObject, eventdata, handles)
% hObject    handle to q4value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of q4value as text
%        str2double(get(hObject,'String')) returns contents of q4value as a double
q = str2double(get(hObject,'String'));
set(hObject,'Value',q);

% --- Executes during object creation, after setting all properties.
function q4value_CreateFcn(hObject, eventdata, handles)
% hObject    handle to q4value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function q5value_Callback(hObject, eventdata, handles)
% hObject    handle to q5value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of q5value as text
%        str2double(get(hObject,'String')) returns contents of q5value as a double
q = str2double(get(hObject,'String'));
set(hObject,'Value',q);

% --- Executes during object creation, after setting all properties.
function q5value_CreateFcn(hObject, eventdata, handles)
% hObject    handle to q5value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function q6value_Callback(hObject, eventdata, handles)
% hObject    handle to q6value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of q6value as text
%        str2double(get(hObject,'String')) returns contents of q6value as a double
q = str2double(get(hObject,'String'));
set(hObject,'Value',q);

% --- Executes during object creation, after setting all properties.
function q6value_CreateFcn(hObject, eventdata, handles)
% hObject    handle to q6value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in sqtQDes.
function sqtQDes_Callback(hObject, eventdata, handles)
% hObject    handle to sqtQDes (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
qvec = [get(handles.q1value,'Value');get(handles.q2value,'Value');...
    get(handles.q3value,'Value');get(handles.q4value,'Value');...
    get(handles.q5value,'Value');get(handles.q6value,'Value')];
setqdes(handles.tg,qvec);



function xvalue_Callback(hObject, eventdata, handles)
% hObject    handle to xvalue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of xvalue as text
%        str2double(get(hObject,'String')) returns contents of xvalue as a double
x = str2double(get(hObject,'String'));
set(hObject,'Value',x);

% --- Executes during object creation, after setting all properties.
function xvalue_CreateFcn(hObject, eventdata, handles)
% hObject    handle to xvalue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function yvalue_Callback(hObject, eventdata, handles)
% hObject    handle to yvalue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of yvalue as text
%        str2double(get(hObject,'String')) returns contents of yvalue as a double
y = str2double(get(hObject,'String'));
set(hObject,'Value',y);

% --- Executes during object creation, after setting all properties.
function yvalue_CreateFcn(hObject, eventdata, handles)
% hObject    handle to yvalue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function omegavalue_Callback(hObject, eventdata, handles)
% hObject    handle to omegavalue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of omegavalue as text
%        str2double(get(hObject,'String')) returns contents of omegavalue as a double
om = str2double(get(hObject,'String'));
set(hObject,'Value',om);

% --- Executes during object creation, after setting all properties.
function omegavalue_CreateFcn(hObject, eventdata, handles)
% hObject    handle to omegavalue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in setxdes.
function setxdes_Callback(hObject, eventdata, handles)
% hObject    handle to setxdes (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
xvec = [get(handles.xvalue,'Value');get(handles.yvalue,'Value');...
        get(handles.omegavalue,'Value')];
setxdes(handles.tg,xvec);



function q1inc_Callback(hObject, eventdata, handles)
% hObject    handle to q1inc (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of q1inc as text
%        str2double(get(hObject,'String')) returns contents of q1inc as a double
q1 = str2double(get(hObject,'String'));
set(hObject,'Value',q1);


% --- Executes during object creation, after setting all properties.
function q1inc_CreateFcn(hObject, eventdata, handles)
% hObject    handle to q1inc (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function q2inc_Callback(hObject, eventdata, handles)
% hObject    handle to q2inc (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of q2inc as text
%        str2double(get(hObject,'String')) returns contents of q2inc as a double
q2 = str2double(get(hObject,'String'));
set(hObject,'Value',q2);

% --- Executes during object creation, after setting all properties.
function q2inc_CreateFcn(hObject, eventdata, handles)
% hObject    handle to q2inc (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function q3inc_Callback(hObject, eventdata, handles)
% hObject    handle to q3inc (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of q3inc as text
%        str2double(get(hObject,'String')) returns contents of q3inc as a double
q3 = str2double(get(hObject,'String'));
set(hObject,'Value',q3);

% --- Executes during object creation, after setting all properties.
function q3inc_CreateFcn(hObject, eventdata, handles)
% hObject    handle to q3inc (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function descontrolmode_Callback(hObject, eventdata, handles)
% hObject    handle to descontrolmode (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of descontrolmode as text
%        str2double(get(hObject,'String')) returns contents of
%        descontrolmode as a double


% --- Executes during object creation, after setting all properties.
function descontrolmode_CreateFcn(hObject, eventdata, handles)
% hObject    handle to descontrolmode (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes on button press in setmacroinc.
function setmacroinc_Callback(hObject, eventdata, handles)
% hObject    handle to setmacroinc (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
qincvec = [get(handles.q1inc,'Value');get(handles.q2inc,'Value');...
        get(handles.q3inc,'Value')];
setmacrostroke(handles.tg,qincvec);


% --- Executes on button press in setcontrolmode.
function setcontrolmode_Callback(hObject, eventdata, handles)
% hObject    handle to setcontrolmode (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
mode = get(handles.descontrolmode,'String');

if strcmp(mode,'Joint Space') || strcmp(mode,'joint space') || strcmp(mode,'joint') || strcmp(mode,'Joint')
    handles.tg.setcontrolmode(1);
elseif strcmp(mode,'Task Space') || strcmp(mode,'task space') || strcmp(mode,'task') || strcmp(mode,'Task')
    handles.tg.setcontrolmode(2);
else
    errordlg({'You must enter one of the following:'; 'Joint Space, joint space, Joint, joint';...
        'Task Space, task space, Task, task'},'Invalid Input','modal')
end


% --- Executes on button press in setSolutionType.
function setSolutionType_Callback(hObject, eventdata, handles)
% hObject    handle to setSolutionType (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
mode = get(handles.desSolutionType,'String');

if strcmp(mode,'Resolved Rate') || strcmp(mode,'resolved rates') || strcmp(mode,'rr') || strcmp(mode,'RR')
    id = handles.tg.getparamid('control_mode/task_space/mode','Value');
    handles.tg.setparam(id,1);
elseif strcmp(mode,'Inv Kin') || strcmp(mode,'inv kin') || strcmp(mode,'ik') || strcmp(mode,'IK')
    id = handles.tg.getparamid('control_mode/task_space/mode','Value');
    handles.tg.setparam(id,2);
else
    errordlg({'You must enter one of the following:'; 'Resolved Rates, resolved rates, RR, rr';...
        'Inv Kin, inv kin, IK, ik'},'Invalid Input','modal')
end


function desSolutionType_Callback(hObject, eventdata, handles)
% hObject    handle to desSolutionType (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of desSolutionType as text
%        str2double(get(hObject,'String')) returns contents of desSolutionType as a double


% --- Executes during object creation, after setting all properties.
function desSolutionType_CreateFcn(hObject, eventdata, handles)
% hObject    handle to desSolutionType (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in enableFileScope.
function enableFileScope_Callback(hObject, eventdata, handles)
% hObject    handle to enableFileScope (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of enableFileScope
enable = get(hObject,'Value');
sc6 = handles.tg.getscope(6);
sc7 = handles.tg.getscope(7);
sc8 = handles.tg.getscope(8);
sc9 = handles.tg.getscope(9);

if enable
    sc6.start; sc7.start; sc8.start; sc9.start;
else
    sc6.stop; sc7.stop; sc8.stop; sc9.start;
end


% --- Executes on button press in initializeTWA.
function initializeTWA_Callback(hObject, eventdata, handles)
% hObject    handle to initializeTWA (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
qvec = [0;0;0;5.6842;4.66442;3.584];
setqdes(handles.tg,qvec);

set(handles.q1value,'Value',qvec(1,1));
set(handles.q1value,'String',num2str(qvec(1,1)));
set(handles.q2value,'Value',qvec(2,1));
set(handles.q2value,'String',num2str(qvec(2,1)));
set(handles.q3value,'Value',qvec(3,1));
set(handles.q3value,'String',num2str(qvec(3,1)));
set(handles.q4value,'Value',qvec(4,1));
set(handles.q4value,'String',num2str(qvec(4,1)));
set(handles.q5value,'Value',qvec(5,1));
set(handles.q5value,'String',num2str(qvec(5,1)));
set(handles.q6value,'Value',qvec(6,1));
set(handles.q6value,'String',num2str(qvec(6,1)));



function kpvalue_Callback(hObject, eventdata, handles)
% hObject    handle to kpvalue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA

% Hints: get(hObject,'String') returns contents of kpvalue as text
%        str2double(get(hObject,'String')) returns contents of kpvalue as a double
s = get(hObject,'String');
kp = str2double(strsplit(s,','));
set(hObject,'Value',kp);


% --- Executes during object creation, after setting all properties.
function kpvalue_CreateFcn(hObject, eventdata, handles)
% hObject    handle to kpvalue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function kivalue_Callback(hObject, eventdata, handles)
% hObject    handle to kivalue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of kivalue as text
%        str2double(get(hObject,'String')) returns contents of kivalue as a double
s = get(hObject,'String');
ki = str2double(strsplit(s,','));
set(hObject,'Value',ki);

% --- Executes during object creation, after setting all properties.
function kivalue_CreateFcn(hObject, eventdata, handles)
% hObject    handle to kivalue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function kdvalue_Callback(hObject, eventdata, handles)
% hObject    handle to kdvalue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of kdvalue as text
%        str2double(get(hObject,'String')) returns contents of kdvalue as a double
s = get(hObject,'String');
kd = str2double(strsplit(s,','));
set(hObject,'Value',kd);

% --- Executes during object creation, after setting all properties.
function kdvalue_CreateFcn(hObject, eventdata, handles)
% hObject    handle to kdvalue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in setpidgain.
function setpidgain_Callback(hObject, eventdata, handles)
% hObject    handle to setpidgain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

kp = transpose(get(handles.kpvalue,'Value'));
ki = transpose(get(handles.kivalue,'Value'));
kd = transpose(get(handles.kdvalue,'Value'));

handles.tg.setparam('Kp',kp);
handles.tg.setparam('Ki',ki);
handles.tg.setparam('Kd',kd);

fprintf('PID Gains ');
fprintf('Kp: [%0.4f,%0.4f,%0.4f] ',kp(1),kp(2),kp(3));
fprintf('Ki: [%0.4f,%0.4f,%0.4f] ',ki(1),ki(2),ki(3));
fprintf('Kd: [%0.4f,%0.4f,%0.4f]\n',kd(1),kd(2),kd(3));


% --- Executes on button press in resetintegrator.
function resetintegrator_Callback(hObject, eventdata, handles)
% hObject    handle to resetintegrator (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.tg.setparam('reset_integ',1);
pause(0.2)
handles.tg.setparam('reset_integ',0);


% --- Executes on button press in enablepid.
function enablepid_Callback(hObject, eventdata, handles)
% hObject    handle to enablepid (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of enablepid
enable = get(hObject,'Value');
handles.tg.setparam('pid_mode',enable);