% get file scope data from xpc target
% elan ahronovich 08/2024

%    READXPCFILE Reads an xpc file format.
%       READXPFILE accepts either the filename from which the
%       data would be read from, or the RAW DATA.
%       DATA should read by MATLAB FREAD command after downloading the datafile from
%       XPCTARGET or by FREAD method of XPCTARGET.FS object.
%       DATA must be a vector of bytes (uint8) read from an
%       xpc file.  These are files written by a scope of
%       type file.
%       Please see the examples below to obtain and read the data from xPC Target
%  
%       Using XPTARGET.FS
%       =================
%       f=xpctarget.fs;
%       h=f.fopen('filename');
%       data=f.fread(h);
%       f.fclose(h);
%       file = readxpcfile(data);
%  
%       Using XPTARGET.FTP
%       ==================
%       xpcftp=xpctarget.ftp
%       xpcftp.get('filename')
%       readxpcfile('filename')
%       or
%       handle=fopen('filename')
%       data=fread(handle,'*uint8'); % Data should be read in uint8 format
%       fclose(handle)
%       data=data';
%       datafile = readxpcfile(data);
%  
%       See also FTP.GET, FS.FOPEN, FS.FREAD

f = xpctarget.ftp;
f.get('xcur.dat')
f.get('qdel.dat')
f.get('q1.dat')
xcur = readxpcfile('xcur.dat');
qdel = readxpcfile('qdel.dat');
q = readxpcfile('q1.dat');



% f = xpctarget.fs;
% h = f.fopen('qdel.dat');
% data = f.read(h);
% f.fclose(h);
% file = readxpcfile(data);