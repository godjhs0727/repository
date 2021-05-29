using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    Rigidbody2D rigid;
    public AudioClip audioBullet;
    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>();
    }
    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Platform")
        {
            Destroy(gameObject);
        }
        else if (collision.gameObject.tag == "SpikeEnemy")
        {
            OnAttack(collision.transform);            
            Destroy(gameObject);
        }
    }
    void OnAttack(Transform enemy)
    {
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse); //�ǰ� ������ �÷��̾ ��¦ ���.
        EnemyMove enemyMove = enemy.GetComponent<EnemyMove>(); //EnemyMove��ũ��Ʈ�� ����ϱ� ���� �ʱ�ȭ
        enemyMove.OnDamaged(); //EnemyMove ��ũ��Ʈ�� publicȭ �� �Լ��� ������
    }
}