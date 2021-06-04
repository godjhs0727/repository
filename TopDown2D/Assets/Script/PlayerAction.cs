using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerAction : MonoBehaviour
{
    public float Speed; //�������� ����
    public GameManager manager;

    Rigidbody2D rigid; //������ �ʱ�ȭ
    float h; //����
    float v; //����
    bool isHorizonMove; //���׿����ڸ� ���� �Ұ�
    Animator anim; //animator�ʱ�ȭ
    Vector3 dirVec;
    GameObject scanObject;

    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>();
        anim = GetComponent<Animator>();
    }
    void Update()
    {
        h = manager.isAction ? 0 : Input.GetAxisRaw("Horizontal"); //���� �ʱ�ȭ ����Ű �̵�
        v = manager.isAction ? 0 : Input.GetAxisRaw("Vertical"); //���� �ʱ�ȭ

        bool hDown = manager.isAction ? false : Input.GetButtonDown("Horizontal"); //���� ������ ����
        bool vDown = manager.isAction ? false : Input.GetButtonDown("Vertical"); //����
        bool hUp = manager.isAction ? false : Input.GetButtonUp("Horizontal"); //���� �� ��
        bool vUp = manager.isAction ? false : Input.GetButtonUp("Vertical"); //����

        if (hDown)
            isHorizonMove = true;
        else if (vDown)
            isHorizonMove = false;
        else if (hUp || vUp)
            isHorizonMove = h != 0;

        //animator
        if (anim.GetInteger("hAxisRaw") != h) //any state�� ��Ƽ� transition�� ��� �߻��ؼ� Walking�� ������� �ʾƼ� h���� ���� �ʴٸ� ó���� 0���� 1�� �ٲ��� �̵��ϸ� 1�� �״�ζ�
        {
            anim.SetInteger("hAxisRaw", (int)h); //�̰ɷ� ��������ְ�
            anim.SetBool("isChange", true); //bool������ ���� �ٲ������ ����
        }
        else if (anim.GetInteger("vAxisRaw") != v)
        {
            anim.SetInteger("vAxisRaw", (int)v);
            anim.SetBool("isChange", true);
        }
        else
            anim.SetBool("isChange", false);

        //Direction
        if (vDown && v == 1)
            dirVec = Vector3.up;
        else if (vDown && v == -1)
            dirVec = Vector3.down;
        else if (hDown && h == -1)
            dirVec = Vector3.left;
        else if (hDown && h == 1)
            dirVec = Vector3.right;

        //Scan Object
        if(Input.GetButtonDown("Jump") && scanObject != null)
        {
            manager.Action(scanObject);
        }
    }

    void FixedUpdate()
    {
        Vector2 moveVec = isHorizonMove ? new Vector2(h, 0) : new Vector2(0, v); //���׿����ڷ� �����̸� ���� �����̸� ������ �̵�
        rigid.velocity = moveVec * Speed;

        //Ray
        Debug.DrawRay(rigid.position, dirVec * 0.7f, new Color(0, 1, 0));
        RaycastHit2D rayHit = Physics2D.Raycast(rigid.position, dirVec, 0.7f, LayerMask.GetMask("Object"));

        if (rayHit.collider != null)
        {
            scanObject = rayHit.collider.gameObject;
        }
        else
            scanObject = null;
    }
}
