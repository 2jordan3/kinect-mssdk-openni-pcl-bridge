@echo ----------
@setlocal
@IF "%OPEN_NI_BIN64%" == "" (SET NIREG_PATH="%OPEN_NI_BIN%\niReg") ELSE (SET NIREG_PATH="%OPEN_NI_BIN64%\niReg64")
%NIREG_PATH%  %0\..\bin\Debug\kinect-mssdk-openni-bridge.dll
@IF NOT "%ERRORLEVEL%" == "0" GOTO ERR
@echo OK!
@GOTO END
:ERR
@echo ----------
@echo [en] Error occured. If you see "Failed to write to the file!" message, try again "as Administrator" by right-clicking the batch file.
@echo [ja] �G���[���������܂����B"Failed to write to the file!" �Ƃ������b�Z�[�W���o�Ă���ꍇ�A�o�b�`�t�@�C�����E�N���b�N���āu�Ǘ��҂Ƃ��Ď��s�v���Ă��������B
:END
@echo ----------
@pause
