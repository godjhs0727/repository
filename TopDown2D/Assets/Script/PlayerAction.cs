using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerAction : MonoBehaviour
{
    public float Speed; //움직임을 위한
    public GameManager manager;

    Rigidbody2D rigid; //물리력 초기화
    float h; //수평
    float v; //수직
    bool isHorizonMove; //삼항연산자를 위한 불값
    Animator anim; //animator초기화
    Vector3 dirVec;
    GameObject scanObject;

    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>();
        anim = GetComponent<Animator>();
    }
    void Update()
    {
        h = manager.isAction ? 0 : Input.GetAxisRaw("Horizontal"); //수평 초기화 방향키 이동
        v = manager.isAction ? 0 : Input.GetAxisRaw("Vertical"); //수직 초기화

        bool hDown = manager.isAction ? false : Input.GetButtonDown("Horizontal"); //수평 누르는 순간
        bool vDown = manager.isAction ? false : Input.GetButtonDown("Vertical"); //수직
        bool hUp = manager.isAction ? false : Input.GetButtonUp("Horizontal"); //수평 뗄 때
        bool vUp = manager.isAction ? false : Input.GetButtonUp("Vertical"); //수직

        if (hDown)
            isHorizonMove = true;
        else if (vDown)
            isHorizonMove = false;
        else if (hUp || vUp)
            isHorizonMove = h != 0;

        //animator
        if (anim.GetInteger("hAxisRaw") != h) //any state로 잡아서 transition이 계속 발생해서 Walking이 재생되지 않아서 h값이 같지 않다면 처음에 0에서 1로 바뀐후 이동하면 1로 그대로라서
        {
            anim.SetInteger("hAxisRaw", (int)h); //이걸로 재생시켜주고
            anim.SetBool("isChange", true); //bool값으로 방향 바뀌었을때 구분
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
        Vector2 moveVec = isHorizonMove ? new Vector2(h, 0) : new Vector2(0, v); //삼항연산자로 수평이면 수평만 수직이면 수직만 이동
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
