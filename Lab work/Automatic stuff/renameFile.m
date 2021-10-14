function renameFile(fileName,testNr)
    newName="Test"+testNr+".mat";
    movefile(fileName,newName);
end

