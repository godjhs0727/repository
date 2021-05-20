using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    public float maxSpeed; //public으로 주면 unity에 inspector 창에 나옴
    public float jump;
    Rigidbody2D rigid;
    SpriteRenderer spriteRenderer;
    Animator anim;
    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>(); //rigid물리력
        //참고 *Rigidbody2D에서 Freeze Z축 체크해주어야 안넘어진다. 오브젝트 회전을 얼리는 옵션
        spriteRenderer = GetComponent<SpriteRenderer>(); //초기화
        anim = GetComponent<Animator>();
    }

    void Update()
    {
        //Jump
        if (Input.GetButtonUp("Jump") && !anim.GetBool("isJumping")) //버튼 뗄때 //Jump는 Space키, Edit ProjectSetting InputManager에서 확인 가능
        {
            rigid.AddForce(Vector2.up * jump, ForceMode2D.Impulse);
            //animation 입히기
            anim.SetBool("isJumping", true);
        }
        //Linear Drag의 공기저항이 2라서 떼는 순간 속도를 안정감 있게 멈추게 한다.
        //멈출때 속도
        if (Input.GetButtonUp("Horizontal")) //버튼 뗄때
        {
            rigid.velocity = new Vector2(rigid.velocity.normalized.x * 0.5f, rigid.velocity.y);
            //normalized는 vector값, 그래서 점찍고 x, 1값으로 만들어 준다.
        }

        //방향 전환
        if (Input.GetButtonDown("Horizontal"))
        {
            spriteRenderer.flipX = Input.GetAxisRaw("Horizontal") == -1;
        }
        
        //Animation
        if(Mathf.Abs(rigid.velocity.x) < 0.3) //Mathf클래스.Abs절대값
        {
            anim.SetBool("isWalking", false);
        }
        else
        {
            anim.SetBool("isWalking", true);
        }
    }
    void FixedUpdate()
    {
        //움직이는 컨트롤, 일반적인 이동 방법
        float h = Input.GetAxisRaw("Horizontal");
        rigid.AddForce(Vector2.right * h, ForceMode2D.Impulse); //rigid에 힘 주기

        //누르고 있는만큼 가속력이 계속 붙기 때문에 한계값을 정해준다, velocity는 속력
        //최대 속도 제한
        if (rigid.velocity.x > maxSpeed) //오른쪽
            rigid.velocity = new Vector2(maxSpeed, rigid.velocity.y); // Vector2(x축, y축)
        else if (rigid.velocity.x < maxSpeed * (-1)) //왼쪽
            rigid.velocity = new Vector2(maxSpeed * (-1), rigid.velocity.y); // Vector2(x축, y축)

        //RayCast : 오브젝트 검색을 위해 Ray를 쏘는 방식
        //Landing platform
        if (rigid.velocity.y < 0)
        {
            Debug.DrawRay(rigid.position, Vector3.down, new Color(0, 1, 0)); //Debug이기 때문에 실제 게임에서는 보이지 않음

            RaycastHit2D rayHit = Physics2D.Raycast(rigid.position, Vector3.down, 1, LayerMask.GetMask("Platform")); //Ray를 아래로 쏘는거
                                                                                                                     //GetMask() : 레이어 이름에 해당하는 정수값을 리턴하는 함수
                                                                                                                     //히트는 오로지 layermask에 해당하는 것들만 스캔한다.
            if (rayHit.collider != null) // 빔을 쏴서 맞았다면
            {
                if (rayHit.distance < 0.5f) //플레이어의 절반 만큼 내려와서 바닥에 닿았을 경우
                {
                    anim.SetBool("isJumping", false);
                }
            }
        }
    }
}
