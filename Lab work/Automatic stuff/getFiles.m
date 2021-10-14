function output = getFiles(path)
%Get all files from current folder or inputarg path, and but it in struct
%with names and var.
if nargin==0
    dirFiles=dir('.\');
else
    dirFiles = dir(path);
end

rIndex=1;
for i = 1:length(dirFiles)
    name = dirFiles(i).name;
    if (length(name)>=5) %#ok<*ISMT>
        S = name(end-3:end);
        if (strcmp(S,".mat"))
            aCell=struct2cell(load(dirFiles(i).name));
            dirFiles(i).('var') = aCell{1}; 
        else
            removeVec(rIndex)=i;
            rIndex=rIndex+1;
        end
    else
        removeVec(rIndex)=i;
        rIndex=rIndex+1;
    end
end
    dirFiles(removeVec)=[];
    output=dirFiles;
end

