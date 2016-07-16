# CKinectDemo2

Adicionar las siguientes lineas a los archivos de configuración del proyuecto

$(VC_IncludePath);$(WindowsSDK_IncludePath);$(KINECTSDK10_DIR)\inc;$(IncludePath)
Las de Library Directories:
$(VC_LibraryPath_x86);$(WindowsSDK_LibraryPath_x86);$(NETFXKitsDir)Lib\um\x86;$(KINECTSDK10_DIR)\lib\x86;$(LibraryPath)
La del Linker->General
$(KINECTSDK10_DIR)/lib/x64
