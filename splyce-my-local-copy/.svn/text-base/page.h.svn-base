class Page{

public:
    void setDspFileName(QString dfn){_dspFileName = dfn;}
    void setFileName(QString fn){_fileName = fn;}
    void setFilePath(QString fp){_filePath = fp;}
    void setOriginalData(QByteArray od){_originalData = od;}
    void setModifiedData(QByteArray md){_modifiedData = md;}
    void setIsRemote(bool ir){_isRemote = ir;}
    
    QString dspFileName(){return _dspFileName;}
    QString fileName(){return _fileName;}
    QString filePath(){return _filePath;}
    QByteArray originalData(){return _originalData;}
    QByteArray modifiedData(){return _modifiedData;}
    bool isRemote(){return _isRemote;}
    
    bool isSynced()
    {
        if(_originalData == _modifiedData)
            return true;
        else
            return false;
    }

private:
    QString _dspFileName; //used to display *file when you save
    QString _fileName; //full path
    QString _filePath; //path - /filename
    QByteArray _originalData;
    QByteArray _modifiedData;
    bool _isRemote; //ftp
};
