#include "DxLib.h"

const char TITLE[] = "TestProgram";

//�E�B���h�E�T�C�Y
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;

int str[50];
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//�E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	/*�E�B���h�E�T�C�Y���蓮�ł͕ύX�����A
	�E�B���h�E�T�C�Y�ɕ����Ċg��ł��Ȃ��悤�ɂ���*/
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	//�^�C�g����ύX
	SetMainWindowText(TITLE);

	//��ʃT�C�Y�̍ő�T�C�Y,�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	//�摜�T�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	//��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0xAF);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//(�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���
	int title = LoadGraph("title.png");
	LoadDivGraph("string.png", 26, 26, 1, 16, 16, str);
	//�Q�[�����[�v�Ŏg���ϐ��̐錾

	//�ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	//1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	//�Q�[�����[�v
	while (1)
	{
		//�ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}
		//�ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		//��ʃN���A
		ClearDrawScreen();

		//�X�V����


		//�`�揈��
		DrawGraph(0, 0, title, true);
		DrawGraph(80, 32, str[12], true);
		DrawGraph(96, 32, str[0], true);
		DrawGraph(112, 32, str[17], true);
		DrawGraph(128, 32, str[8], true);
		DrawGraph(144, 32, str[14], true);

		DrawGraph(80, 48, str[2], true);

		DrawGraph(240, 48, str[2], true);
		DrawGraph(256, 48, str[1], true);
		DrawGraph(272, 48, str[1], true);
		DrawGraph(288, 48, str[1], true);

		DrawGraph(384, 32, str[22], true);
		DrawGraph(400, 32, str[14], true);
		DrawGraph(416, 32, str[17], true);
		DrawGraph(432, 32, str[11], true);
		DrawGraph(448, 32, str[3], true);

		DrawGraph(512, 32, str[19], true);
		DrawGraph(528, 32, str[8], true);
		DrawGraph(544, 32, str[12], true);
		DrawGraph(560, 32, str[4], true);

		//(�_�u���o�b�t�@)����
		ScreenFlip();

		//20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		//Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1)
		{
			break;
		}

		//ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}