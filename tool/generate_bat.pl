&generate("install", "", ["Release"]);
&generate("install-debug", "", ["Debug"]);
&generate("uninstall", "-u", ["Release", "Debug"]);

sub generate {
	my($file_name, $opt, $dirs) = @_;
	$file_name .= ".bat";
	
	open(FILE, ">../$file_name") || die;
	
	for $dir (@$dirs) {
		print FILE <<EOT;
\@echo ----------
"%OPEN_NI_BIN%\\niReg" ${opt} %0\\..\\bin\\${dir}\\kinect-mssdk-openni-bridge.dll
\@IF NOT "%ERRORLEVEL%" == "0" GOTO ERR
\@echo OK!
EOT
	}
	
	print FILE <<EOT;
\@GOTO END
:ERR
\@echo ----------
\@echo [en] Error occured. If you see "Failed to write to the file!" message, try again "as Administrator" by right-clicking the batch file.
\@echo [ja] �G���[���������܂����B"Failed to write to the file!" �Ƃ������b�Z�[�W���o�Ă���ꍇ�A�o�b�`�t�@�C�����E�N���b�N���āu�Ǘ��҂Ƃ��Ď��s�v���Ă��������B
:END
\@echo ----------
\@pause
EOT
	
	close(FILE);
}

