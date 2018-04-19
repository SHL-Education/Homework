#if 0

VFS는 Super Block인 ext2_sb_info와 같은 것들을 읽어 super_block에 채워넣는다.
그리고 읽고자 하는 파일에 대한 메타 정보를
ext2_inode와 같은 것들을 읽어 inode에 채운다.

이후에 디렉토리 엔트리인 ext2_dir_entry를 읽어 dentry 구조체에 채우고
현재 위치 정보에 대한 정보를 위해 path 구조체를 채운 이후
실제 File에 대한 상세한 정보를 기록하기 위해 file 구조체를 채운다.
각각 적절한 값을 채워넣어 실제 필요한 파일을 Task와 연결시킨다.

#endif
