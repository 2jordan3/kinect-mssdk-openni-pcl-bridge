@echo ----------
@setlocal
@SET BUILD_TYPE=Release
@IF "%OPEN_NI_BIN64%" == "" (SET NIREG_PATH="%OPEN_NI_BIN%\niReg") ELSE (SET NIREG_PATH="%OPEN_NI_BIN64%\niReg64")
@IF EXIST "%KINECTSDK_DIR%\lib" (SET KINECTSDK_VERSION=Beta2) ELSE (SET KINECTSDK_VERSION=Beta1)
%NIREG_PATH%  %0\..\bin\kinect-mssdk-openni-bridge-%KINECTSDK_VERSION%%BUILD_TYPE%.dll
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
