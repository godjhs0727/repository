using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    public GameManager gameManager;
    public float maxSpeed; //public으로 주면 unity에 inspector 창에 나옴
    public float jump;
    Rigidbody2D rigid;
    SpriteRenderer spriteRenderer;
    Animator anim;
    CapsuleCollider2D capCollider;
    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>(); //rigid물리력
        //참고 *Rigidbody2D에서 Freeze Z축 체크해주어야 안넘어진다. 오브젝트 회전을 얼리는 옵션
        spriteRenderer = GetComponent<SpriteRenderer>(); //초기화
        capCollider = GetComponent<CapsuleCollider2D>();
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
        if (Input.GetButton("Horizontal"))
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

    void OnCollisionEnter2D(Collision2D collision)
    {
        if(collision.gameObject.tag == "Enemy")
        {
            //Attack
            if (rigid.velocity.y < 0 && transform.position.y > collision.transform.position.y)
            {
                OnAttack(collision.transform);
            }
            else
                OnDamaged(collision.transform.position);
        }
    }

    void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.gameObject.tag == "Item")
        {
            bool isBronze = collision.gameObject.name.Contains("Bronze");
            bool isSilver = collision.gameObject.name.Contains("Silver");
            bool isGold = collision.gameObject.name.Contains("Gold");

            if (isBronze)
                gameManager.stagePoint += 50;
            else if (isSilver)
                gameManager.stagePoint += 100;
            else if (isGold)
                gameManager.stagePoint += 300;
            //Point
            gameManager.stagePoint += 100;
            //Deactive Item
            collision.gameObject.SetActive(false);
        }
        else if(collision.gameObject.tag == "Finish")
        {
            //Next Stage
            gameManager.NextStage();
        }
    }
    void OnAttack(Transform enemy)
    {
        //Point
        gameManager.stagePoint += 100;
        //Reaction Force
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse);
        //Enemy Die
        EnemyMove enemyMove = enemy.GetComponent<EnemyMove>();
        enemyMove.OnDamaged();
    }

    void OnDamaged(Vector2 targetPos) //collision2D라서 Vector2 값
    {
        //Health Down
        gameManager.HealthDown();
        //layer 변경 번호
        gameObject.layer = 11;
        //스프라이트 색 RGB 다음 4번째 투명도
        spriteRenderer.color = new Color(1, 1, 1, 0.4f);
        //튕겨나가는거 Reaction Force
        //호출할때 new사용
        int dirc = transform.position.x - targetPos.x > 0 ? 1 : -1;
        rigid.AddForce(new Vector2(dirc, 1) * 7, ForceMode2D.Impulse);

        //Animation
        anim.SetTrigger("doDamaged");

        Invoke("OffDamaged", 3);

    }

    void OffDamaged()
    {
        gameObject.layer = 10;
        spriteRenderer.color = new Color(1, 1, 1, 1);
    }

    public void OnDie()
    {
        //Sprite Alpha
        spriteRenderer.color = new Color(1, 1, 1, 0.4f);
        //Sprite Flip Y
        spriteRenderer.flipY = true;
        //Collider Disable
        capCollider.enabled = false;
        //Die Effect Jump
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse);
    }
    public void VelocityZero()
    {
        rigid.velocity = Vector2.zero;
    }
}
