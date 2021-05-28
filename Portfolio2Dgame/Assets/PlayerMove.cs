using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    public GameObject bulletObj;
    public GameManager gameManager;
    Rigidbody2D rigid; //rigid 플레이어
    SpriteRenderer spriteRenderer; //방향 전환하기 위한 spriterenderer flip
    Animator anim; //애니메이션 효과
    CapsuleCollider2D capCollider;
    float maxSpeed = 3; //스피드를 기본 3으로 설정 변경을 원하면 변수 선언만 해놓고 유니티 안에서 변경가능
    public float JumpPower; //유니티에서 변경 처음 default 0
    void Awake() //초기화 하기 위한 Awake
    {
        rigid = GetComponent<Rigidbody2D>(); //초기화
        spriteRenderer = GetComponent<SpriteRenderer>(); //초기화
        anim = GetComponent<Animator>(); //초기화
        capCollider = GetComponent<CapsuleCollider2D>();
    }
    void Update()
    {
        //점프
        if (Input.GetButtonUp("Jump") && !anim.GetBool("isJumping")) //Jump는 프로젝트 세팅 input에서 space바 이기에 만약 스페이스 가 떨어지는 순간 그리고 애니메이션이 jumping 중이 아닌 상태일때
        {
            rigid.AddForce(Vector2.up * JumpPower, ForceMode2D.Impulse); //AddForce로 힘을 가한다 Vector2가 위로 JumpPower만큼 올리고 ForceMode2D.Impulse
            anim.SetBool("isJumping", true); //애니메이션 isJumping 이 true
        }

        //멈출때의 공기저항 바닥을 마찰력 0으로 설정되어있기에 멈출때 많이 미끄러져서 덜 미끄러지게 저항 설정
        if(Input.GetButtonUp("Horizontal")) //Horizontal이 projectSetting Input에서 방향키 이기에 positive면 오른쪽 반대면 왼쪽
        {
            rigid.velocity = new Vector2(rigid.velocity.normalized.x * 0.5f, rigid.velocity.y); //rigid.velocity는 속도, normalized는 벡터크기를 1로 만든 상태이고 0.5곱해서 더 천천히,
            //소수는 뒤에 반드시 f붙혀줘야한다.
        }
        //방향전환
        if(Input.GetButton("Horizontal")) //화살표 좌우를 누른다, 버튼을 누를때 뗄때 관계없이
        {
            spriteRenderer.flipX = Input.GetAxisRaw("Horizontal") == -1; //방향 전환할때 스프라이트 그림이 좌우 X축 기준으로 바뀐다.
        }   
        if(Input.GetButtonUp("Fire1"))
        {
            if (spriteRenderer.flipX)
            {
                Fire();
            }
            else
            {
                GameObject bullet = Instantiate(bulletObj, transform.position, transform.rotation);
                Rigidbody2D rigid = bullet.GetComponent<Rigidbody2D>();
                rigid.AddForce(Vector2.right * 5, ForceMode2D.Impulse);

            }
        }
    }
    void Fire()
    {
        GameObject bullet = Instantiate(bulletObj, transform.position, transform.rotation);
        Rigidbody2D rigid = bullet.GetComponent<Rigidbody2D>();
        rigid.AddForce(Vector2.right * (-5), ForceMode2D.Impulse);
    }
    void FixedUpdate()
    {
        //이동구현
        float h = Input.GetAxisRaw("Horizontal"); //화살표 좌우 기준 positive = 오른쪽 반대는 왼쪽
        rigid.AddForce(Vector2.right * h, ForceMode2D.Impulse); //물리력이 이동한다.

        //속도 가속력 제한 그냥 두면 배로 속도가 증가해버림, 일정 속도 유지
        if (rigid.velocity.x > maxSpeed) //만약 x축 속도가 maxSpeed보다 크면  여기는 오른쪽 부분
            rigid.velocity = new Vector2(maxSpeed, rigid.velocity.y); //스피드는 maxSpeed
        else if (rigid.velocity.x < maxSpeed * (-1)) //왼쪽 부분이기에 -1 곱해줌
            rigid.velocity = new Vector2(maxSpeed * (-1), rigid.velocity.y); //마찬가지로 -maxSpeed로
        
        //걷기 애니메이션
        if (Mathf.Abs(rigid.velocity.x) < 0.3) //mathf클래스를 사용하여 Abs는 절대값 고로 오른쪽이든 왼쪽이든 속도가 0.3보다 낮으면
            anim.SetBool("isWalking", false); //걷는 애니메이션 효과 해제
        else
            anim.SetBool("isWalking", true); //발동

        //떨어질때 착지
        if (rigid.velocity.y < 0) //점프하고 나서 떨어지니깐 아래로 가는 속도기 때문에 마이너스
        {
            Debug.DrawRay(rigid.position, Vector3.down, new Color(0, 1, 0)); //Debug는 game화면엔 안나오고 Scene화면으로 확인 할수 있다. 광선을 플레이어의 위치에서 아래로 초록색 광선 쏜다.
            RaycastHit2D rayHit = Physics2D.Raycast(rigid.position, Vector3.down, LayerMask.GetMask("Platform")); //이제 광선을 목표물에 때린다. 플레이어가, 아래로, layer가 Platform인거에 때림

            if(rayHit.collider != null) //만약 물체에 맞았다면
            {
                if(rayHit.distance < 0.5) //간격이 0.5아래면 점핑 애니메이션을 해제시킨다.                
                    anim.SetBool("isJumping", false);              
            }
        }
    }
    void OnCollisionEnter2D(Collision2D collision) //피격시
    {
        if (collision.gameObject.tag == "Enemy") //Enemy tag를 가진 collider를 가진 물체와 접촉시
        {
            if (rigid.velocity.y < 0 && transform.position.y > collision.transform.position.y) //플레이어가 낙하할때, 그리고 피격대상의 y포지션이 충돌부위보다 커질때
            {
                OnAttack(collision.transform);
            }
            else
            {
                if (gameManager.health < 2)
                    OnDie();
                else
                    OnDamaged(collision.transform.position); //데미지 함수 호출(플레이어가 맞은 collider)
            }
        }
        else if(collision.gameObject.tag == "SpikeEnemy")
        {
            if (gameManager.health < 2)
                OnDie();
            else
                OnDamaged(collision.transform.position);
        }
    }
    void OnTriggerEnter2D(Collider2D collision)
    {
        capCollider.isTrigger = true;
        if (collision.tag == "Ring")
        {
            gameManager.stagePoint += 100;
            collision.gameObject.SetActive(false);
            
        }
        else if (collision.tag == "Finish")
        {
            gameManager.NextStage();
        }

    }
    void OnTriggerExit2D(Collider2D collision)
    {
        capCollider.isTrigger = false;   
    }
    void OnAttack(Transform enemy)
    {
        gameManager.stagePoint += 100;
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse); //피격 성공시 플레이어가 살짝 뜬다.
        EnemyMove enemyMove = enemy.GetComponent<EnemyMove>(); //EnemyMove스크립트를 사용하기 위해 초기화
        enemyMove.OnDamaged(); //EnemyMove 스크립트의 public화 된 함수를 가져옴
    }
    void OnDamaged(Vector2 targetPos) //(Enter2D이기 때문에 Vector2), 무적 상태
    {
        //Health Down
        gameManager.HealthDown();
        gameObject.layer = 8; //Player게임 오브젝트의 레이어가 8번으로 변경, 8번은 PlayerDamaged인데 project세팅에서 Enemy와 충돌 안하게 설정해놓음 일종의 무적상태
        
        //색 변경
        spriteRenderer.color = new Color(1, 1, 1, 0.4f); //뒤에 4번째는 투명도

        //맞으면 튕겨나감
        int dirc = transform.position.x/*맞은 상대방 그러니깐 플레이어*/ - targetPos.x > 0 ? 1 : -1; //삼항연산자, 양수면 1, 음수면 -1, 양수라면 플레이어가 오른쪽에 있고 음수면 반대
        rigid.AddForce(new Vector2(dirc, 1) * 7, ForceMode2D.Impulse); //물체가 힘을 받는다

        anim.SetTrigger("Damage"); //트리거 파라미터로 놓았다. 맞으면 발동하는 anystate 애니메이션, anystate는 어떤 애니메이션이 작동하던간에 당장 실행 시킬수 있음
        Invoke("OffDamaged", 5); //3초뒤에 함수를 불러서 데미지상태는 3초간만 유지 이후에 원래대로
    }
    void OffDamaged()
    {
        gameObject.layer = 7; //7번째 Player layer로 다시 돌아오게
        spriteRenderer.color = new Color(1, 1, 1, 1); //투명도 해제
    }
        
    public void OnDie()
    {
        anim.SetTrigger("Fall");
        Time.timeScale = 0;
        //spriteRenderer.color = new Color(1, 1, 1, 0.4f); 
        //spriteRenderer.flipY = true; //거꾸로 뒤집기
        capCollider.enabled = false; //고체화 해제하여 중력은 그대로 아래로 떨어짐
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse); //살짝 뜸
    }
    public void VelocityZero()
    {
        rigid.velocity = Vector2.zero;
    }

}
